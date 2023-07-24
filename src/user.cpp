#include "../include/user.hpp"

size_t User::_id = 0;

User::User(const std::string username, const std::string password)
    : _username(username), _password(password) {
  _id++;
};

User::~User() = default;