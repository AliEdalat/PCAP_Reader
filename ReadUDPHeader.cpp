#include "ReadUDPHeader.h"

ReadUDPHeader::ReadUDPHeader(const u_char* start_header, int prev_header_size,
 int pkthdr_len) : ReadInternetProtocol(start_header, prev_header_size, pkthdr_len){
	//std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size);
	//start_header_=start_header_temp;
	prev_header_size_=prev_header_size;
	//std::unique_ptr<UDPHR> udp_header_temp (reinterpret_cast<UDPHR*> (const_cast<u_char*> (start_header) + prev_header_size));
	//udp_header_=std::move(udp_header_temp);

	udp_header_ = std::make_shared<UDPHR> (*(reinterpret_cast<UDPHR*> (const_cast<u_char*> (start_header) + prev_header_size)));

	source_port_ = ntohs(udp_header_->source);
	des_port_ = ntohs(udp_header_->dest);
	//std::unique_ptr<u_char> data_temp (const_cast<u_char*> (start_header) + prev_header_size + sizeof(UDPHR));
	//data_=std::move(data_temp);

	data_ = std::make_shared<u_char> (*(const_cast<u_char*> (start_header) + prev_header_size + static_cast<int>(sizeof(UDPHR))));

	data_len_ = pkthdr_len - (prev_header_size_ + static_cast<int>(sizeof(UDPHR)));
	for (int i = 0; i < data_len_; i++) {
		if ((data_.get()[i] >= 32 && data_.get()[i] <= 126) || data_.get()[i] == 10 || data_.get()[i] == 11 || data_.get()[i] == 13) {
			data_string_ += static_cast<char>((data_.get())[i]);
		} else {
			data_string_ += ".";
		}
	}
}