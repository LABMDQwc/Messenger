#pragma once
#include <string>

class User {
 private:
  const std::string _username;
  std::string _password;

 public:
  User(const std::string_view&, const std::string_view&);
};
