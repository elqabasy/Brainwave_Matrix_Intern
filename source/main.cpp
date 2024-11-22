#include "atm/ATM.hpp"
#include "transactions/WithdrawTransaction.hpp"
#include "transactions/DepositTransaction.hpp"
#include <iostream>

int main() {
    ATM atm("Downtown Branch", "24/7 Service", "atm_log.txt");

    // Display ATM info
    atm.displayInfo();

    // Simulate card insertion and PIN entry
    std::cout << "Insert your card...\n";
    atm.insertCard();
    std::string pin;
    std::cout << "Enter your PIN: ";
    std::cin >> pin; // User input for PIN
    atm.enterPIN(pin);

    if (atm.isAuthenticated()) {
        // Perform operations after successful authentication
        int choice;
        do {
            std::cout << "\n1. Withdraw Cash\n2. Deposit Cash\n3. Check Balance\n4. Exit\n";
            std::cout << "Choose an option: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    // Withdraw cash
                    double amount;
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    WithdrawTransaction withdraw(atm, amount);
                    atm.executeTransaction(withdraw);
                    break;
                }
                case 2: {
                    // Deposit cash
                    double amount;
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    DepositTransaction deposit(atm, amount);
                    atm.executeTransaction(deposit);
                    break;
                }
                case 3: {
                    // Check balance
                    double balance = atm.getBankDB().getBalance(atm.getCurrentCard());
                    std::cout << "Current Balance: " << balance << "\n";
                    break;
                }
                case 4:
                    // Exit
                    std::cout << "Thank you for using the ATM. Goodbye!\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 4);
    } else {
        std::cout << "Authentication failed. Please try again.\n";
    }

    // Simulate technical support login
    std::string techPassword;
    std::cout << "\nEnter technical support password: ";
    std::cin >> techPassword; // User input for technical support password
    atm.techLogin(techPassword);

    if (atm.isTechAuthenticated()) {
        // Perform technical support operations
        int techChoice;
        do {
            std::cout << "\n1. Report Issue\n2. Schedule Maintenance\n3. Check ATM Status\n4. Exit\n";
            std::cout << "Choose an option: ";
            std::cin >> techChoice;

            switch (techChoice) {
                case 1: {
                    // Report an issue
                    std::string issue;
                    std::cout << "Describe the issue: ";
                    std::cin.ignore(); // Clear the input buffer
                    std::getline(std::cin, issue);
                    atm.reportIssue(issue);
                    break;
                }
                case 2: {
                    // Schedule maintenance
                    std::string date;
                    std::cout << "Enter maintenance date (YYYY-MM-DD): ";
                    std::cin >> date;
                    atm.scheduleMaintenance(date);
                    break;
                }
                case 3:
                    // Check ATM status
                    atm.checkATMStatus();
                    break;
                case 4:
                    // Exit
                    std::cout << "Exiting technical support mode.\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (techChoice != 4);
    } else {
        std::cout << "Technical support authentication failed.\n";
    }

    return 0;
}
