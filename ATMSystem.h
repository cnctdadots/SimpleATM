#pragma once
#include <string>
#include "User.h"

void loadUsers(std::map<std::string, User> &users, const std::string& filename);
void saveUsers(const std::map<std::string, User> &users, const std::string &filename);
void clearInput();