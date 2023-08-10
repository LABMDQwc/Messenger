#include "../include/chat.hpp"

Chat::Chat(User& user1, User& user2) {
  this->_members.emplace(&user1);
  this->_members.emplace(&user2);
}

void Chat::write(const std::string& mes, const User& user) {
  this->_messages.push_back(Message(mes, user));
}

Chat::Chat::Message::Message(std::string str, const User& user)
    : _message(str), _user(user) {
  _time = std::chrono::system_clock::now();
};
