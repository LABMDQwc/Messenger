#pragma once
#include <boost/asio.hpp>
using namespace boost::asio;

class Server {
 private:
  io_context& _service;
  ip::tcp::acceptor _acceptor;

 public:
  Server(io_context&, size_t);
  void start();
};
void read(ip::tcp::socket&);