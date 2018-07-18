#include "ReadEthernetHeader.h"

ReadEthernetHeader::ReadEthernetHeader(const u_char* start_header , int prev_header_size){
	std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size); 
	std::unique_ptr<IP> ethernet_header_temp (reinterpret_cast<IP*> (start_header_.get()));
	ethernet_header_=ethernet_header_temp;
	ether_dest_host_=std::string(static_cast<char*> (ethernet_header_->ether_dhost))
	ether_source_host_=std::string(static_cast<char*> (ethernet_header_->ether_shost))
	ether_type_=(ntohs(ethernet_header_->ether_type)==ETHERTYPE_IP)?"IP":(ntohs(ethernet_header_->ether_type)==ETHERTYPE_PUP)?"PUP":(ntohs(ethernet_header_->ether_type)==ETHERTYPE_ARP)?"ARP":"";
}