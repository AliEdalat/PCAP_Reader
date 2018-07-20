#include "ReadTCPHeader.h"

ReadTCPHeader::ReadTCPHeader(const u_char* start_header, int reminder)
 : ReadInternetProtocol(){
	//std::unique_ptr<u_char> start_header_temp (const_cast<u_char*> (start_header) + prev_header_size);
	//start_header_=start_header_temp;
	//prev_header_size_=prev_header_size;
	//std::unique_ptr<TCPHR> tcp_header_temp (reinterpret_cast<TCPHR*> (const_cast<u_char*> (start_header) + prev_header_size));
	//tcp_header_=std::move(tcp_header_temp);

	/*tcp_header_ = std::make_shared<const TCPHR> (*(reinterpret_cast<const TCPHR*> (const_cast<u_char*> (start_header))));

	source_port_ = ntohs(tcp_header_->source);
	des_port_ = ntohs(tcp_header_->dest);

	data_ = std::make_shared<char> (*(reinterpret_cast<char*>(const_cast<u_char*> (start_header) + sizeof(struct tcphdr))));
*/	std::shared_ptr<struct tcphdr> tcpHeader = std::make_shared<struct tcphdr>(*(reinterpret_cast<struct tcphdr*>(const_cast<u_char*>(start_header))));
 	//const struct tcphdr* tcpHeader = (struct tcphdr*)(start_header);
	source_port_ = ntohs((tcpHeader.get())->source);
	des_port_ = ntohs((tcpHeader.get())->dest);
	
	//std::shared_ptr<u_char> data = std::make_shared<u_char>(*(start_header + sizeof(struct tcphdr)));
	u_char* data = const_cast<u_char*>(start_header + sizeof(struct tcphdr));
	//dataLength = pkthdr->len - (sizeof(struct ether_header) + sizeof(struct ip) + sizeof(struct tcphdr));
	//std::unique_ptr<u_char> data_temp (const_cast<u_char*> (start_header) + prev_header_size + sizeof(TCPHR));
	//data_=std::move(data_temp);
	data_len_ = reminder;
	data_string_="";
	for (int i = 0; i < data_len_; i++) {
		//std::cout<< (char)data[i];
		if ((data[i] >= 32 && data[i] <= 126) || data[i] == 10 || data[i] == 11 || data[i] == 13) {
			data_string_ += (char)(data[i]);
		} else {
			data_string_ += ".";
		}
	}
	//std::cout<<std::endl;
}