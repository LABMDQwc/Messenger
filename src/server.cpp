#include "../include/server.hpp"
#include <iostream>
boost::asio::streambuf b(65000);

Server::Server(io_context& io_context, size_t port)
    : _service(io_context),
      _acceptor(_service, ip::tcp::endpoint(ip::tcp::v4(), port)) {}
void Server::start() {
  ip::tcp::socket socket(_service);
  _acceptor.async_accept(socket, [&](const boost::system::error_code& ec) {
    if (!ec) {
      std::cout << "connected\n";
      read(socket);
      start();
    } else {
      std::cout << ec.message() << std::endl;
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
                       for (auto const& word : message) {
                         std::cout << word;
                       }
                       b.consume(b.size());
                       read(socket);
                     } else {
                       std::cout << ec.message() << std::endl;
                     }
                   });
}