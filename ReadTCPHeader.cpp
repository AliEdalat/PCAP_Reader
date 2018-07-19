#include "ReadTCPHeader.h"

ReadTCPHeader::ReadTCPHeader(const u_char* start_header, int prev_header_size,
 int pkthdr_len) : ReadInternetProtocol(start_header, prev_header_size, pkthdr_len){
	//std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size);
	//start_header_=start_header_temp;
	prev_header_size_=prev_header_size;
	//std::unique_ptr<TCPHR> tcp_header_temp (reinterpret_cast<TCPHR*> (const_cast<u_char*> (start_header) + prev_header_size));
	//tcp_header_=std::move(tcp_header_temp);

	tcp_header_ = std::make_shared<TCPHR> (*(reinterpret_cast<TCPHR*> (const_cast<u_char*> (start_header) + prev_header_size)));

	source_port_ = ntohs(tcp_header_->source);
	des_port_ = ntohs(tcp_header_->dest);

	data_ = std::make_shared<u_char> (*(const_cast<u_char*> (start_header) + prev_header_size + sizeof(TCPHR)));

	//std::unique_ptr<u_char> data_temp (const_cast<u_char*> (start_header) + prev_header_size + sizeof(TCPHR));
	//data_=std::move(data_temp);
	data_len_ = pkthdr_len - (prev_header_size_ + sizeof(TCPHR));
	for (int i = 0; i < data_len_; i++) {
		if ((data_.get()[i] >= 32 && data_.get()[i] <= 126) || data_.get()[i] == 10 || data_.get()[i] == 11 || data_.get()[i] == 13) {
			data_string_ += (char)data_.get()[i];
		} else {
			data_string_ += ".";
		}
	}
}