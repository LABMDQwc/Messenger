#pragma once
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/write.hpp>
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

void reg(ip::tcp::socket&);

void auth(ip::tcp::socket&);

bool find_acc(const std::string& log, const std::string& pass);