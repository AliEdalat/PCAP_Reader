#ifndef READ_IP_HEADER_H
#define READ_IP_HEADER_H

#include <iostream>
#include <string>
#include <memory>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
typedef struct ip IP;

class ReadIPHeader
{
private:
	std::unique_ptr<u_char> start_header_;
	std::unique_ptr<IP> ip_header_;
	char source_ip_ [INET_ADDRSTRLEN];
	char dest_ip_ [INET_ADDRSTRLEN];
	std::string ip_protocol_;
	int size_;
public:
	ReadIPHeader(const u_char* start_header , int prev_header_size);
	inline std::string get_source_ip(){return std::string(source_ip_);}
	inline std::string get_dest_ip(){return std::string(dest_ip_);}
	inline std::string get_ip_protocol(){return ip_protocol_;}
	inline int get_ip_header_size(){return size_;}
	~ReadIPHeader();
	
};

#endif