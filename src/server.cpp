#include "../include/server.hpp"
#include <iostream>

void show_chat(const class Chat& chat) {
  for (auto it : chat._messages) {
    std::cout << it->_user->_username << ":           " << it->_message
              << std::endl;
  }
}