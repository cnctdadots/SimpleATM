#include "ATMSystem.h"
#include <fstream>
#include <limits>

void loadUsers(std::map<std::string, User>& users, const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin)
        return;

    std::string card, pin, acctType;
    int balance;
    while (fin >> card >> pin)
    {
        User u(pin);
        while (fin >> acctType) {
            if (acctType == "###")
                break;
            fin >> balance;
            u.accounts[acctType] = Account(acctType, balance);
        }
        users[card] = u;
    }

    fin.close();
}

void saveUsers(const std::map<std::string, User> &users, const std::string& filename) {
    std::ofstream fout(filename);
    for (const auto& [card, user] : users) {
        fout << card << " " << user.pin << "\n";
        for (const auto& [type, account]: user.accounts) {
            fout << type << " " << account.balance << "\n";
        }
        fout << "###\n";
    }
    fout.close();
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
