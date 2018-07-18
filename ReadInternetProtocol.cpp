#include "ReadInternetProtocol.h"

ReadInternetProtocol::ReadInternetProtocol(const u_char* start_header , int prev_header_size , int pkthdr_len){
	std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size);
	start_header_=start_header_temp;
	prev_header_size_=prev_header_size;
	pkthdr_len_= pkthdr_len;
}