#include <iostream>
#include "ATMSystem.h"

int main() {
    std::map<std::string, User> users;
    loadUsers(users, "accounts.txt");

    std::string cardInserted, enteredPin, selectedAccount;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;
    int choice;
    double amount;

    std::cout << "Please insert your card (type card number): ";
    std::getline(std::cin, cardInserted);

    if (users.find(cardInserted) == users.end()) {
        std::cout << "Card not recognized.\n";
        return 0;
    }

    User& currentUser = users[cardInserted];

    while (attempts < MAX_ATTEMPTS) {
        std::cout << "Enter PIN: ";
        std::cin >> enteredPin;
        if (enteredPin == currentUser.pin) {
            std::cout << "PIN accepted.\n";
            break;
        } else {
            std::cout << "Incorrect PIN.\n";
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        std::cout << "Too many attempts. Session terminated.\n";
        return 0;
    }

    std::cout << "\nAvailable accounts: ";
    for (auto& [name, acc] : currentUser.accounts)
        std::cout << name << " ";
    std::cout << "\nSelect account: ";
    std::cin >> selectedAccount;

    if (currentUser.accounts.find(selectedAccount) == currentUser.accounts.end()) {
        std::cout << "Account not found.\n";
        return 0;
    }

    Account& activeAccount = currentUser.accounts[selectedAccount];

    do {
        std::cout << "\n--- ATM Menu (" << selectedAccount << ") ---\n";
        std::cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nChoose: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            clearInput();
            std::cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1:
                activeAccount.checkBalance();
                break;
            case 2:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                activeAccount.deposit(amount);
                saveUsers(users, "accounts.txt");
                break;
            case 3:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                activeAccount.withdraw(amount);
                saveUsers(users, "accounts.txt");
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}