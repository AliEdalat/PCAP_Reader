#ifndef READ_TCP_HEADER_H
#define READ_TCP_HEADER_H

#include "ReadInternetProtocol.h"
#include <netinet/tcp.h>
typedef struct tcphdr TCPHR;

class ReadTCPHeader:public ReadInternetProtocol
{
private:
	std::unique_ptr<TCPHR> tcp_header_;
public:
	ReadTCPHeader(const u_char* start_header , int prev_header_size);
	//~ReadTCPHeader();
	
};

#endif
