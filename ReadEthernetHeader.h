#ifndef READ_ETHERNET_HEADER_H
#define READ_ETHERNET_HEADER_H

//#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct ether_header ETHHR;

class ReadEthernetHeader
{
private:
	std::shared_ptr<ETHHR> ethernet_header_;
	std::string ether_dest_host_;
	std::string ether_source_host_;
	std::string ether_type_;

public:
	ReadEthernetHeader(const u_char* start_header);
	std::string get_ether_type() const;
	std::string get_dest_host() const;
	std::string get_source_host() const;
	//~ReadEthernetHeader();
	
};

#endif