#include "../include/user.hpp"

User::User(const std::string_view& username, const std::string_view& password)
    : username_(username), password_(password){};