#ifndef READ_TCP_HEADER_H
#define READ_TCP_HEADER_H

#include "ReadInternetProtocol.h"
#include <netinet/tcp.h>
#include <iostream>

typedef struct tcphdr TCPHR;

class ReadTCPHeader : public ReadInternetProtocol
{
private:
	std::shared_ptr<TCPHR> tcp_header_;
public:
	ReadTCPHeader(const u_char* start_header, int prev_header_size, int pkthdr_len);
	//~ReadTCPHeader();
	
};

#endif
