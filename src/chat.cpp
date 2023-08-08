#include "../include/chat.hpp"

Chat::Chat(User& user1, User& user2) {
  this->members_.emplace(&user1);
  this->members_.emplace(&user2);
}

void Chat::write(const std::string mes, User& user) {
  this->messages_.push_back(Message(mes, user));
}

Chat::Chat::Message::Message(std::string str, const User& user)
    : message_(str), user_(user) {
  time_ = std::chrono::system_clock::now();
};
