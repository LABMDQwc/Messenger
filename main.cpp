#include <boost/asio.hpp>
#include <iostream>
using namespace std;
#define PORT 15001
using namespace boost::asio;

class ServerChat {
public:
    ServerChat(io_context &service, size_t port) : _service(service), _acceptor(service, ip::tcp::endpoint(ip::tcp::v4(), port)) {
      ip::tcp::socket socket(_service);
      cout << "debug point 1: " << socket.is_open() << ' ' << _service.stopped() << endl;
      _acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
                              cout << "debug point 2: " << socket.is_open() << ' ' << _service.stopped() << endl;
                              if (!ec) {
                                cout << "Connected" << endl;
                                read(socket, _service);
                                write(socket, _service);
                              } else {
                                cout << ec.message() << endl;
                              }
      });
      _service.run();
      cout << "debug point 3: " << socket.is_open() << ' ' << _service.stopped() << endl;
    }
private:
    static void write(ip::tcp::socket &socket, io_context &_service) {
      cout << "debug point 4: " << socket.is_open() << ' ' << _service.stopped() << endl;

      cout << "trying to write" << endl;
      string message = "hello\n";
      async_write(socket, buffer(message), [&](const boost::system::error_code &ec, size_t) {
        cout << "debug point 5: " << socket.is_open() << ' ' << _service.stopped() << endl;
        if (!ec) {
          cout << "sending message" << endl;
        } else {
          cout << ec.message() << endl;
        }
      });
    }
    static void read(ip::tcp::socket &socket, io_context &_service) {
      cout << "debug point 6: " << socket.is_open() << ' ' << _service.stopped() << endl;
      cout << "trying to read" << endl;
      boost::asio::streambuf stream;
      async_read_until(socket, stream, "\n", [&](const boost::system::error_code &ec, streamsize bytes) {
        cout << "debug point 7: " << socket.is_open() << ' ' << _service.stopped() << endl;
        if (!ec) {
//          cout << "reading message with bytes: " << bytes << endl;
//          cout.write(res.data(), bytes) << endl;
          std::stringstream message;
          message << std::istream(&stream).rdbuf();
          stream.consume(bytes);
          cout << message.str() << endl;
        } else {
          cout << ec.message() << endl;
        }
      });
    }
    io_context &_service;
    boost::asio::streambuf streambuf;
    ip::tcp::acceptor _acceptor;
};

int main() {
  io_context service;
  ServerChat srv(service, PORT);

  return 0;
}