#ifndef READ_UDP_HEADER_H
#define READ_UDP_HEADER_H

#include "ReadInternetProtocol.h"
#include <netinet/udp.h>
typedef struct udphdr UDPHR; 

class ReadUDPHeader : public ReadInternetProtocol
{
private:
	std::shared_ptr<const UDPHR> udp_header_;
public:
	ReadUDPHeader(const u_char* start_header, int reminder);
	//~ReadUDPHeader();
	
};

#endif