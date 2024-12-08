#include "Bank.hpp"
#include <iostream>
#include <stdexcept>



using namespace std;

void displayMenu() {
    cout << "\n===== BANK SYSTEM MENU =====\n"
              << "1. Create User\n"
              << "2. Create Account\n"
              << "3. Deposit\n"
              << "4. Withdraw\n"
              << "5. Transfer Money\n"
              << "6. View User Details\n"
              << "7. List All Accounts\n"
              << "8. List Transaction History\n"
              << "9. Exit\n"
              << "Enter your choice: ";
}

int main() {
    Bank bank;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        system("cls");

        try {
            if (choice == 1) {
                cout << "Creating new User..." << endl << endl;
                string name, email;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                bank.createUser(name, email);
            } else if (choice == 2) {
                cout << "Creating new Account..." << endl << endl;
                int userId;
                double initialDeposit;
                cout << "Enter User ID: ";
                cin >> userId;
                cout << "Enter initial deposit: ";
                cin >> initialDeposit;
                bank.createAccount(userId, initialDeposit);
            } else if (choice == 3) {
                cout << "Deposit an Amount..." << endl << endl;
                int accountId;
                double amount;
                cout << "Enter Account ID: ";
                cin >> accountId;
                cout << "Enter deposit amount: ";
                cin >> amount;
                bank.deposit(accountId, amount);
            } else if (choice == 4) {
                cout << "Withdraw an Amount..." << endl << endl;
                int accountId;
                double amount;
                cout << "Enter Account ID: ";
                cin >> accountId;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                bank.withdraw(accountId, amount);
            } else if (choice == 5) {
                cout << "Transfer to an Amount..." << endl << endl;
                int fromAccountId, toAccountId;
                double amount;
                cout << "Enter From Account ID: ";
                cin >> fromAccountId;
                cout << "Enter To Account ID: ";
                cin >> toAccountId;
                cout << "Enter amount: ";
                cin >> amount;
                bank.transferMoney(fromAccountId, toAccountId, amount);
            } else if (choice == 6) {
                cout << "Displaying user details..." << endl << endl;
                int userId;
                cout << "Enter User ID: ";
                cin >> userId;
                bank.showUserDetails(userId);
            } else if (choice == 7) {
                cout << "Displaying accounts..." << endl << endl;
                bank.listAllAccounts();
            } else if (choice == 8) {
                cout << "Displaying transaction history..." << endl << endl;
                int accountId;
                cout << "Enter Account ID: ";
                cin >> accountId;
                bank.listTransactionHistory(accountId);
            } else if (choice == 9) {
                cout << "Saving data..." << endl << endl;
                bank.saveData();
                cout << "Exiting... Data saved successfully.\n";
                break;
            } else {
                cout << "[ERROR] " << "Sorry! an error ocurred" << endl << endl;
                cout << "Invalid choice. Try again.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
