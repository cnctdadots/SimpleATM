#pragma once
#include <string>
#include <iostream>

class Account {
    public:
        std::string type;
        int balance;

        Account() : type(""), balance(0) {}
        Account(std::string t, int b) : type(t), balance(b) {}

        void checkBalance() const {
            std::cout << "Account type is : " << type << ". Account Balance: $" << balance << std::endl;
        }
        void deposit(int amount) {
            if (amount <= 0) {
                std::cout << "Invalid deposit amount." << std::endl;
                return;
            }
            balance += amount;
            std::cout << "Deposited amount: $" << amount << " to" << type << " account. Current balance: $" << balance << std::endl;
        }
        void withdraw(int amount){
            if (amount <=0) {
                std::cout << "Invalid withdrawal amount." << std::endl;
            } else if(amount > balance) {
                std::cout << "Insufficient balance in " << type << " account." << std::endl;
            } else {
                balance -= amount;
                std::cout << "Withdraw amount: $" << amount << " from " << type << " account. New balance" << balance << std::endl;
            }
        }
};
