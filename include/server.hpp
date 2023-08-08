#pragma once
#include <boost/asio.hpp>
using namespace boost::asio;

class Server {
 private:
  io_context& service_;
  ip::tcp::acceptor acceptor_;

 public:
  Server(io_context&, size_t);
  void start();
};
void read(ip::tcp::socket&);