# SimpleATM – C++ ATM Simulation

This is a terminal-based Simple ATM simulation built in modern C++17. It allows users to insert a card, verify their PIN, choose from multiple account types (e.g., Savings or Checking), and perform ATM operations with persistent data storage. (Check the txt file as an example here)

---

## Features
- **PIN verification** with 3-attempt limit  
- **Multiple users (cards)** with multiple accounts each  
- Supports **checking balance**, **deposit**, and **withdraw**  
- **Account selection** (e.g. Savings, Checking)  
- **Persistent storage** of all user data to `accounts.txt`  
- Modular design with C++ header/source file separation

---
## Project File Structure

SimpleATM  
&emsp;&emsp;- main.cpp – Main application logic and ATM menu  
&emsp;&emsp;- Account.h – Account class (represents each bank account)  
&emsp;&emsp;- User.h – User class (stores PIN and list of accounts)  
&emsp;&emsp;- ATMSystem.h – Helper function declarations (file I/O, input handling)  
&emsp;&emsp;- ATMSystem.cpp – Implementation of ATMSystem utilities  
&emsp;&emsp;- accounts.txt – User data file: card number, PIN, and account balances  
&emsp;&emsp;- README.md – Project overview and usage guide

---

## Getting Started

### Requirements

- C++17 compatible compiler (e.g., `g++`, `clang++`)
- A terminal (Linux/macOS/WSL/Git Bash)

---

### Build & Run

```bash
g++ -std=c++17 main.cpp ATMSystem.cpp -o atm
./atm
```

---

### SAMPLE EXAMPLE to get user data (check txt file)
```bash
card123 1234
Savings 1000
Checking 500
###
card456 5678
Savings 2000
Checking 800
###
```
---

### How to run the test code (in main.cpp)
#### Usage flow
- `Insert card` - Type one of the cards from the file (accounts.txt)
- `Enter pin` - Enter the related pin (you can test for multiple times, expected to terminate after max trials)
- `Select account` - Select 'Savings' or 'Checkings'
- `Choose an option` - Choose either check balance, or withdrawal or deposit or exit. 