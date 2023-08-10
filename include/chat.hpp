#pragma once
#include <chrono>
#include <list>
#include <unordered_set>
#include "user.hpp"

class Chat {
 private:
  std::unordered_set<User*> _members;

 public:
  Chat(User&, User&);
  void write(const std::string&, const User&);

  class Message {
   private:
    std::chrono::system_clock::time_point _time;
    std::string _message;
    const User& _user;

   public:
    Message(std::string, const User&);
  };

 private:
  std::list<Message> _messages;
};
