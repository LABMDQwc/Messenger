#include "../include/server.hpp"
#define PORT 19518

int main() {
  io_context service;
  Server srv(service, PORT);
  srv.start();
  return 0;
}
