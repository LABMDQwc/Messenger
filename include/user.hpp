#ifndef _MESSENGER_USER_HPP
#define _MESSENGER_USER_HPP
#include <string>
#include "../include/chat.hpp"

class User {
 public:
  User(const std::string username, const std::string password);
  ~User();

 private:
  static size_t _id;
  std::string _username;
  std::string _password;
  friend void show_chat(const class Chat& chat);
};

#endif  //_MESSENGER_USER_HPP
