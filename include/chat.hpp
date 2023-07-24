#ifndef _MESSENGER_CHAT_HPP
#define _MESSENGER_CHAT_HPP
#include <chrono>
#include <list>
#include <vector>
#include "user.hpp"

class Chat {
 public:
  Chat(const class User& user1, const class User& user2);
  ~Chat();
  class Message {
   public:
    Message(std::string str, const class User& user, class Chat& chat);
    ~Message();

   private:
    std::chrono::system_clock::time_point _time;
    std::string _message;
    size_t _message_id;
    const User* _user;
    Chat* _chat;
    friend void show_chat(const class Chat& chat);
  };
  void add(std::string str, const class User& user);

 private:
  size_t _id;
  std::vector<const class User*> _members;
  std::list<class Message*> _messages;
  friend void show_chat(const class Chat& chat);
};

#endif  //_MESSENGER_CHAT_HPP
