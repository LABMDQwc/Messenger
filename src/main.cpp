#include "../include/chat.hpp"
#include "../include/server.hpp"

int main() {
  User Mark("mark", "pass1234");
  User Nikita("red", "pass4321");
  Chat chat12(Mark, Nikita);
  chat12.add("hello how are you", Mark);
  chat12.add("hello im fine and you", Nikita);
  chat12.add("im too", Mark);
  chat12.add("that's nice", Nikita);
  show_chat(chat12);
  return 0;
}