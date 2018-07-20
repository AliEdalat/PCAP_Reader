#include "ReadInternetProtocol.h"

ReadInternetProtocol::ReadInternetProtocol(){
	//std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size);
	//start_header_ = std::make_shared<u_char> (*(const_cast<u_char*> (start_header)));
	//start_header_=std::move(start_header_temp);
	//prev_header_size_=prev_header_size;
	source_port_=0;
	data_len_=0;
	des_port_=0;
	data_string_ = "";
}