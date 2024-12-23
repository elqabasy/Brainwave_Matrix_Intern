#include "atm/ATM.hpp"
#include "transactions/WithdrawTransaction.hpp"
#include "transactions/DepositTransaction.hpp"
#include <iostream>
using namespace std;

int main() {
    ATM atm("Downtown Branch", "24/7 Service", "atm_log.txt");

    // Display ATM info
    atm.displayInfo();

    // Simulate card insertion and PIN entry
    cout << "Insert your card...\n";
    atm.insertCard();
    string pin;
    cout << "Enter your PIN: ";
    cin >> pin; // User input for PIN
    atm.enterPIN(pin);

    if (atm.isAuthenticated()) {
        // Perform operations after successful authentication
        int choice;
        do {
            cout << "\n1. Withdraw Cash\n2. Deposit Cash\n3. Check Balance\n4. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    // Withdraw cash
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    WithdrawTransaction withdraw(atm, amount);
                    atm.executeTransaction(withdraw);
                    break;
                }
                case 2: {
                    // Deposit cash
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    DepositTransaction deposit(atm, amount);
                    atm.executeTransaction(deposit);
                    break;
                }
                case 3: {
                    // Check balance
                    double balance = atm.getBankDB().getBalance(atm.getCurrentCard());
                    cout << "Current Balance: " << balance << "\n";
                    break;
                }
                case 4:
                    // Exit
                    cout << "Thank you for using the ATM. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 4);
    } else {
        cout << "Authentication failed. Please try again.\n";
    }

    // Simulate technical support login
    string techPassword;
    cout << "\nEnter technical support password: ";
    cin >> techPassword; // User input for technical support password
    atm.techLogin(techPassword);

    if (atm.isTechAuthenticated()) {
        // Perform technical support operations
        int techChoice;
        do {
            cout << "\n1. Report Issue\n2. Schedule Maintenance\n3. Check ATM Status\n4. Exit\n";
            cout << "Choose an option: ";
            cin >> techChoice;

            switch (techChoice) {
                case 1: {
                    // Report an issue
                    string issue;
                    cout << "Describe the issue: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, issue);
                    atm.reportIssue(issue);
                    break;
                }
                case 2: {
                    // Schedule maintenance
                    string date;
                    cout << "Enter maintenance date (YYYY-MM-DD): ";
                    cin >> date;
                    atm.scheduleMaintenance(date);
                    break;
                }
                case 3:
                    // Check ATM status
                    atm.checkATMStatus();
                    break;
                case 4:
                    // Exit
                    cout << "Exiting technical support mode.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (techChoice != 4);
    } else {
        cout << "Technical support authentication failed.\n";
    }

    return 0;
}
