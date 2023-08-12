#include "../include/server.hpp"
#include <fstream>
#include <iostream>
boost::asio::streambuf b(1024);
std::string login;
std::string pass;

Server::Server(io_context& io_context, size_t port)
    : _service(io_context),
      _acceptor(_service, ip::tcp::endpoint(ip::tcp::v4(), port)) {}

void Server::start() {
  ip::tcp::socket socket(_service);
  _acceptor.async_accept(socket, [&](const boost::system::error_code& ec) {
    if (!ec) {
      auth(socket);
      start();
    }
  });
  _service.run();
}

void read(ip::tcp::socket& socket) {
  async_read_until(socket, b, '\n',
                   [&](const boost::system::error_code& ec, size_t bytes) {
                     if (!ec) {
                       b.commit(bytes);
                       std::istream is(&b);
                       std::vector<std::string> message;
                       std::string w;
                       while (is.peek() != '\r' && is >> w) {
                         message.push_back(w);
                         message.emplace_back(" ");
                       }
                       message.emplace_back("\n");
                       b.consume(bytes);
                       read(socket);
                     }
                   });
}

void auth(ip::tcp::socket& socket) {
  async_write(socket, boost::asio::buffer("Please, enter login\n"), [&](const boost::system::error_code&, size_t) {
    async_read_until(socket, b, '\n',
                     [&](const boost::system::error_code& ec, size_t bytes) {
                       if (!ec) {
                         std::istream is(&b);
                         is >> login;
                         b.consume(bytes);
                         async_write(socket, boost::asio::buffer("Please, enter password\n"), [&](const boost::system::error_code&, size_t) {
                           async_read_until(socket, b, '\n',
                                            [&](const boost::system::error_code& ec, size_t bytes) {
                                              if (!ec) {
                                                std::istream is(&b);
                                                is >> pass;
                                                b.consume(bytes);
                                                std::ofstream users_db("users_db", std::ios::app);
                                                users_db << login << ';' << pass << '\n';
                                                users_db.close();
                                              }
                                            });
                         });
                       }
                     });
  });
}