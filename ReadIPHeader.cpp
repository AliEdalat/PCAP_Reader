#include "ReadIPHeader.h"

ReadIPHeader::ReadIPHeader(const u_char* start_header , int prev_header_size){
	//std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size);
	//start_header_ = std::move(unique_start_header_); 
	//std::unique_ptr<IP> ip_header_temp (reinterpret_cast<IP*> (const_cast<u_char*> (start_header) + prev_header_size));
	//ip_header_= std::move(unique_ip_header_);
	//start_header_=start_header_temp;
	//ip_header_=std::move(ip_header_temp);
	ip_header_ = std::make_shared<IP> (*(reinterpret_cast<IP*> (const_cast<u_char*> (start_header) + prev_header_size)));
	inet_ntop(AF_INET , &(ip_header_->ip_src) , source_ip_ , INET_ADDRSTRLEN);
    inet_ntop(AF_INET , &(ip_header_->ip_dst) , dest_ip_ , INET_ADDRSTRLEN);
    ip_protocol_ = (ip_header_->ip_p == IPPROTO_TCP)?"TCP":
    			(ip_header_->ip_p == IPPROTO_IP)?"IP":
    			(ip_header_->ip_p == IPPROTO_UDP)?"UDP":"";
    size_=static_cast<int>(sizeof(struct ip));
}	