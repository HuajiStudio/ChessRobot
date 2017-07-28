// ChessRobot.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <boost/asio.hpp>
#include "stdafx.h"

using namespace boost::asio;

io_service service;
ip::tcp::socket sock(service);
ip::tcp::acceptor acc;
char buff[512];

const int DEFAULT_PORT = 6489;

int main(int argc, char **argv)
{
	ip::tcp::endpoint ep;
	if (argc == 2)
		ep = ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), std::stoi(argv[1]));
	else
		ep = ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), DEFAULT_PORT);
	sock.async_connect(ep, connect_handler);
	sock.async_read_some(buff, read_handler);
	acc = ip::tcp::acceptor(service, ep);
	service.run();
    return 0;
}

void connect_handler(const boost::system::error_code & ec)
{
	if (ec != boost::system::errc::success)
	{
		fprintf(stderr, "Error when connecting to server: %s", ec.message().c_str());
		return;
	}
}

void read_handler(const boost::system::error_code & error, size_t bytes_transferred)
{
	if (error != boost::system::errc::success)
	{
		fprintf(stderr, "Error when connecting to server: %s", error.message().c_str());
		return;
	}
	// TODO: Do something with buffer
}
