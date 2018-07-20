#ifndef READ_INTERNET_PROTOCOL_H
#define READ_INTERNET_PROTOCOL_H

//#include <iostream>
#include <string>
#include <memory>
#include <netinet/in.h>
#include <pcap.h>


class ReadInternetProtocol
{
protected:
	u_int source_port_;
	u_int des_port_;
	std::string data_string_;
	int data_len_;
	std::shared_ptr<char> data_;
	//u_char* data_;
	//std::shared_ptr<u_char> start_header_;
	//u_char* start_header_;
	//int prev_header_size_;
	int reminder_;
	// inline void set_data(u_char* data){data_=data;}
	// inline void set_data_len(int data_len){data_len_=data_len;}
	// inline void set_data_string(std::string data_str){data_string_=data_str;}
	// inline void set_source_port(int source_port){source_port_=source_port;}
	// inline void set_des_port(int des_port){des_port_==des_port;}
public:
	ReadInternetProtocol();
	//~ReadInternetProtocol();
	inline char* get_data(){return data_.get();}
	inline int get_data_len(){return data_len_;}
	inline std::string get_data_string(){return data_string_;}
	inline u_int get_source_port(){return source_port_;}
	inline u_int get_des_port(){return des_port_;}
};

#endif