
# Bank System (C++)

This is a simple C++ Bank System that simulates a banking system allowing users to manage accounts, make transactions, and track balances. It demonstrates object-oriented principles and data management using C++.

## Features

- Create accounts for users.
- Deposit and withdraw funds from accounts.
- Transfer money between accounts.
- View account details and transaction history.
- Simple error handling for invalid operations.

## Project Structure

```
BANK_SYSTEM/
│
├── source/                       # Source code files
│   ├── Bank.cpp                  # Implementation of the Bank class
│   ├── Account.cpp               # Implementation of the Account class
│   ├── User.cpp                  # Implementation of the User class
│   ├── Transaction.cpp           # Implementation of the Transaction class
│   └── Utils/                    # Utility functions
│       └── Utils.cpp             # Helper functions for logging and ID generation
│
├── include/                      # Header files for the classes
│   ├── Bank.hpp                  # Header for the Bank class
│   ├── Account.hpp               # Header for the Account class
│   ├── User.hpp                  # Header for the User class
│   ├── Transaction.hpp           # Header for the Transaction class
│   └── Utils/                    # Utility headers
│       └── Utils.hpp             # Header for utility functions
│
├── build/                        # Build directory
│
├── main.cpp                      # Main entry point of the application
├── CMakeLists.txt                # CMake build configuration file
└── README.md                     # This README file
```

## Requirements

- C++17 or later
- CMake 3.10 or higher
- A C++ compiler (e.g., GCC, Clang, MSVC)

## Setup

1. **Clone the repository:**
   ```bash
   git clone <repository_url>
   cd BankSystem
   ```

2. **Build the project:**

   - Create a build directory:
     ```bash
     mkdir build
     cd build
     ```

   - Run CMake to configure the project:
     ```bash
     cmake ..
     ```

   - Compile the project using `make`:
     ```bash
     make
     ```

   This will generate an executable file named `BankSystem.exe`.

## Usage

1. **Run the program:**
   After building, you can run the application:
   ```bash
   ./BankSystem
   ```

2. **Features:**
   - Create users, create accounts for users, deposit, withdraw, and transfer funds.
   - You can interact with the system by modifying the `main.cpp` file or adding features to simulate different bank operations.

## Example Usage

### Create an Account:
```cpp
Bank bank;
User user1(1, "John Doe", "john@example.com");
bank.addUser(user1);
Account account1(101, user1.getId(), 5000.00);
bank.addAccount(account1);
```

### Deposit Funds:
```cpp
bank.depositFunds(101, 1000.00);
```

### Transfer Money:
```cpp
bank.transferMoney(101, 102, 500.00);
```

### View Transaction History:
```cpp
bank.listTransactionHistory(101);
```

### Show User Details:
```cpp
bank.showUserDetails(1);
```

## File Descriptions

- **Bank.cpp / Bank.hpp**: Implements the core logic for managing users, accounts, and transactions.
- **Account.cpp / Account.hpp**: Defines the Account class, which includes properties like account ID, owner, and balance.
- **User.cpp / User.hpp**: Defines the User class, which holds information about a bank customer (ID, name, and email).
- **Transaction.cpp / Transaction.hpp**: Handles transaction details, including transfers between accounts.
- **Utils.cpp / Utils.hpp**: Helper functions for logging, generating unique IDs, etc.

## Future Enhancements

This project is designed to be easily extendable. Future features could include:

- Support for account types (e.g., savings, checking).
- Enhanced security features (e.g., password protection, 2FA).
- Integration with a database for persistent data storage.
- Improved user interface (UI).
