#pragma once
#include <chrono>
#include <list>
#include <unordered_set>
#include "user.hpp"

class Chat {
 public:
  Chat(User& user1, User& user2);
  void write(const std::string mes, User& user);

  class Message {
   public:
    Message(std::string str, const User& user);

    std::chrono::system_clock::time_point time_;
    std::string message_;
    const User& user_;
  };
  std::unordered_set<User*> members_;
  std::list<Message> messages_;
};
