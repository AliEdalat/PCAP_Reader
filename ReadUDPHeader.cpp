#include "ReadUDPHeader.h"

ReadUDPHeader::ReadUDPHeader(const u_char* start_header , int prev_header_size , int pkthdr_len){
	std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size);
	start_header_=start_header_temp;
	prev_header_size_=prev_header_size;
	std::unique_ptr<UDPHR> tcp_header_temp (reinterpret_cast<UDPHR*> (start_header_.get()));
	tcp_header_=tcp_header_temp;
	source_port_ = ntohs(tcp_header_->source);
	des_port_ = ntohs(tcp_header_->dest);
	std::unique_ptr<u_char> data_temp (start_header_.get() + sizeof(UDPHR));
	data_=data_temp;
	data_len_ = pkthdr_len - (prev_header_size_ + sizeof(UDPHR));
	for (int i = 0; i < data_len_; i++) {
		if ((data_[i] >= 32 && data_[i] <= 126) || data_[i] == 10 || data_[i] == 11 || data_[i] == 13) {
			data_string_ += (char)data_[i];
		} else {
			data_string_ += ".";
		}
	}
}