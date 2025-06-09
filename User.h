#pragma once
#include <string>
#include <map>
#include "Account.h"

class User {
    public:
        std::string pin;
        std::map<std::string, Account> accounts;

        User() {
            pin = -1;
            accounts["Savings"] = Account();
            accounts["Checkings"] = Account();
        }
        User(std::string p) {
            pin = p;
            accounts["Savings"] = Account("Savings", 1000);
            accounts["Checkings"] = Account("Checkings", 500);
        }
};