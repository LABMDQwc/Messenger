#pragma once
#include <string>

class User {
 public:
  User(const std::string_view& username, const std::string_view& password);

  size_t _id;
  const std::string username_;
  std::string password_;
};