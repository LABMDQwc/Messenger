#include "../include/server.hpp"
#include <fstream>
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

void reg(ip::tcp::socket& socket) {
  async_write(
      socket, boost::asio::buffer("Please, enter login\n"),
      [&](const boost::system::error_code&, size_t) {
        async_read_until(
            socket, b, '\n',
            [&](const boost::system::error_code& ec, size_t bytes) {
              if (!ec) {
                std::istream is(&b);
                is >> login;
                b.consume(bytes);
                async_write(
                    socket, boost::asio::buffer("Please, enter password\n"),
                    [&](const boost::system::error_code&, size_t) {
                      async_read_until(
                          socket, b, '\n',
                          [&](const boost::system::error_code& ec,
                              size_t bytes) {
                            if (!ec) {
                              std::istream is(&b);
                              is >> pass;
                              b.consume(bytes);
                              std::ofstream users_db("users_db", std::ios::app);
                              users_db << login << ';'
                                       << std::hash<std::string>{}(pass)
                                       << '\n';
                              users_db.close();
                              async_write(
                                  socket,
                                  boost::asio::buffer("You have sign up\n"),
                                  [&](const boost::system::error_code&,
                                      size_t) {});
                            }
                          });
                    });
              }
            });
      });
}

void auth(ip::tcp::socket& socket) {
  async_write(
      socket, boost::asio::buffer("Please, enter login\n"),
      [&](const boost::system::error_code&, size_t) {
        async_read_until(
            socket, b, '\n',
            [&](const boost::system::error_code& ec, size_t bytes) {
              if (!ec) {
                std::istream is(&b);
                is >> login;
                b.consume(bytes);
                async_write(
                    socket, boost::asio::buffer("Please, enter password\n"),
                    [&](const boost::system::error_code&, size_t) {
                      async_read_until(
                          socket, b, '\n',
                          [&](const boost::system::error_code& ec,
                              size_t bytes) {
                            if (!ec) {
                              std::istream is(&b);
                              is >> pass;
                              if (find_acc(login, pass)) {
                                async_write(
                                    socket,
                                    boost::asio::buffer("You have log in\n"),
                                    [](const boost::system::error_code&,
                                       size_t) {});
                              } else {
                                async_write(
                                    socket,
                                    boost::asio::buffer("Please, sign up\n"),
                                    [&](const boost::system::error_code&,
                                        size_t) { reg(socket); });
                              }
                              b.consume(bytes);
                            }
                          });
                    });
              }
            });
      });
}

bool find_acc(const std::string& log, const std::string& pass) {
  std::ifstream users_db("users_db");
  std::string db_login, db_pass;
  while (!users_db.eof()) {
    std::getline(users_db, db_login, ';');
    std::getline(users_db, db_pass, '\n');
    if (db_login == log &&
        db_pass == std::to_string(std::hash<std::string>{}(pass))) {
      users_db.close();
      return true;
    }
  }
  users_db.close();
  return false;
}