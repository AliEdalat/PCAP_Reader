#include "ReadEthernetHeader.h"

ReadEthernetHeader::ReadEthernetHeader(const u_char* start_header){
	//std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size); 
	//std::unique_ptr<ETHHR> ethernet_header_temp (reinterpret_cast<ETHHR*> (const_cast<u_char*> (start_header)));
	//ethernet_header_=std::move(ethernet_header_temp);

	ethernet_header_ = std::make_shared<ETHHR> (*(reinterpret_cast<ETHHR*> (const_cast<u_char*> (start_header))));

	ether_dest_host_=std::string(reinterpret_cast<char*> (ethernet_header_->ether_dhost));
	ether_source_host_=std::string(reinterpret_cast<char*> (ethernet_header_->ether_shost));
	ether_type_=(ntohs(ethernet_header_->ether_type)==ETHERTYPE_IP)?"IP":
	(ntohs(ethernet_header_->ether_type)==ETHERTYPE_PUP)?"PUP":
	(ntohs(ethernet_header_->ether_type)==ETHERTYPE_ARP)?"ARP":"";
}

std::string ReadEthernetHeader::get_ether_type() const {return ether_type_;}
std::string ReadEthernetHeader::get_dest_host() const {return ether_dest_host_;}
std::string ReadEthernetHeader::get_source_host() const {return ether_source_host_;}