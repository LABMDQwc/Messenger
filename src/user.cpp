#include "../include/user.hpp"

User::User(const std::string_view& username, const std::string_view& password)
    : _username(username), _password(password){};