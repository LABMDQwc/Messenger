#include "../include/server.hpp"
#include <fstream>
#include <iostream>
boost::asio::streambuf b(1024);
std::string POST;

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

void auth(ip::tcp::socket& socket) {
  async_read_until(socket, b, "\nEND", [&](const boost::system::error_code&, size_t bytes) {
    std::istream is(&b);
    is >> POST;
    if (POST == "LOGIN") {
      sign_in(socket, is);
      b.consume(bytes);
    } else {
      sign_up(socket, is);
      b.consume(bytes);
      auth(socket);
    }
  });
}

void sign_in(ip::tcp::socket& socket, std::istream &is) {
  std::string login;
  std::string pass;
  is >> login;
  is >> pass;
  if (find_acc(login, pass)) {
  async_write(socket, boost::asio::buffer("LOGIN"), 
  [&](const boost::system::error_code&, size_t) {});
  } else {
  async_write(socket, boost::asio::buffer("LOGIN_FAIL"), 
  [&](const boost::system::error_code&, size_t) {
    auth(socket);
  });
  }
}

void sign_up(ip::tcp::socket& socket, std::istream &is) {
  std::string login;
  std::string pass;
  is >> login;
  is >> pass;
  async_write(socket, boost::asio::buffer("REGISTER"), 
  [&](const boost::system::error_code&, size_t) {});
  std::ofstream users_db("users_db", std::ios::app);
  users_db << login << ';' << std::hash<std::string>{}(pass) << '\n';
  users_db.close();
}

bool find_acc(const std::string& login, const std::string& pass) {
  std::fstream users_db("users_db");
  std::string db_login, db_pass;
  while (!users_db.eof()) {
    std::getline(users_db, db_login, ';');
    std::getline(users_db, db_pass, '\n');
    if (db_login == login &&
        db_pass == std::to_string(std::hash<std::string>{}(pass))) {
      users_db.close();
      return true;
    }
  }
  users_db.close();
  return false;
}