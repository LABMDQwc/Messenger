#include "../include/chat.hpp"

Chat::Chat(const class User& user1, const class User& user2) {
  this->_members.push_back(&user1);
  this->_members.push_back(&user2);
}

Chat::~Chat() = default;

void Chat::add(std::string str, const class User& user) {
  Message* message = new Message(str, user, *this);
  this->_messages.push_back(message);
}

Chat::Chat::Message::Message(std::string str, const class User& user,
                             class Chat& chat)
    : _message(str), _user(&user), _chat(&chat) {
  _time = std::chrono::system_clock::now();
};

Chat::Chat::Message::~Message() = default;