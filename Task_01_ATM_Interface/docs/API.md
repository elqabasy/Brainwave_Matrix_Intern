# ATM Interface API Documentation

## Table of Contents

- ATM
  - [ATMInterface](#atm)

- COMPONENTS
  - [Vault](#vault)
  - [BankDB](#bankdb)
  - [ATMScreen](#atmscreen)
  - [SoundUnit](#soundunit)
  - [CardReader](#cardreader)

- Transactions

  - [Transaction](#transaction)
  - [WithdrawTransaction](#withdrawtransaction)
  - [DepositTransaction](#deposittransaction)

- Utils

  - [Logger](#logger)
  - [Constants](#constants)
  - [TechnicalSupport](#technicalsupport)

## Overview

The ATM Interface project simulates the core functionalities of an Automated Teller Machine (ATM). This documentation provides a detailed overview of the classes, methods, and components involved in the project.

## Classes and Methods

### ATM

The `ATM` class manages the overall operations of the ATM, including card processing, transactions, and technical support.

#### Attributes

- `managedBy` (string): Information about the entity managing the ATM.
- `cardReader` (CardReader): Handles card reading operations.
- `cashDispenser` (CashDispenser): Manages cash dispensing.
- `receiptPrinter` (ReceiptPrinter): Prints transaction receipts.
- `bankDB` (BankDB): Simulates bank database operations.
- `vault` (Vault): Manages the ATM vault.
- `screen` (ATMScreen): Manages screen display operations.
- `soundUnit` (SoundUnit): Handles sound feedback.
- `logger` (Logger): Logs system events and errors.
- `currentCard` (string): Stores the current card number.
- `authenticated` (bool): Indicates user authentication status.
- `techAuthenticated` (bool): Indicates technical support authentication status.
- `techSupport` (TechnicalSupport): Manages technical support operations.

#### Methods

- `ATM(const string& loc, const string& pref, const string& logFilename)`
  - Constructor that initializes the ATM with location, preferences, and log file.
- `void displayInfo() const`
  - Displays ATM information.
- `void insertCard()`
  - Simulates card insertion.
- `void enterPIN(const string& pin)`
  - Validates entered PIN.
- `void techLogin(const string& password)`
  - Authenticates technical support access.
- `void executeTransaction(Transaction& transaction)`
  - Executes a specified transaction.
- `void reportIssue(const string& issue)`
  - Reports an issue.
- `void scheduleMaintenance(const string& date)`
  - Schedules maintenance.
- `void checkATMStatus()`
  - Checks the ATM status.
- `bool isAuthenticated() const`
  - Returns the authentication status of the user.
- `bool isTechAuthenticated() const`
  - Returns the authentication status of the technical support.

### Vault

The `Vault` class manages the cash storage within the ATM.

#### Methods

- `Vault()`
  - Constructor that initializes the vault with an initial amount of money.
- `void addMoney(double amount)`
  - Adds money to the vault.
- `bool withdrawMoney(double amount)`
  - Withdraws money from the vault if sufficient funds are available.
- `double checkBalance() const`
  - Checks the current balance in the vault.

### CardReader

The `CardReader` class simulates card reading operations.

#### Methods

- `string readCard() const`
  - Reads and returns the card number.

### ATMScreen

The `ATMScreen` class manages display operations on the ATM screen.

#### Methods

- `void display(const string& message) const`
  - Displays a message on the screen.

### SoundUnit

The `SoundUnit` class handles sound feedback in the ATM.

#### Methods

- `void playSound(const string& sound) const`
  - Plays a specified sound.

### Logger

The `Logger` class logs events and errors to a log file.

#### Attributes

- `logFile` (ofstream): File stream to store log entries.

#### Methods

- `Logger(const string& filename)`
  - Constructor that opens the log file.
- `~Logger()`
  - Destructor that closes the log file.
- `void log(const string& message) const`
  - Logs a message to the log file.

### BankDB

The `BankDB` class simulates bank database operations.

#### Attributes

- `accounts` (unordered_map<string, pair<string, double>>): Stores account information with card number as key.

#### Methods

- `BankDB()`
  - Constructor that initializes the bank database with sample accounts.
- `bool validateCard(const string& cardNumber)`
  - Validates the card number.
- `bool validatePIN(const string& cardNumber, const string& pin)`
  - Validates the PIN for the given card number.
- `double getBalance(const string& cardNumber)`
  - Retrieves the balance for the given card number.
- `void updateBalance(const string& cardNumber, double amount)`
  - Updates the balance for the given card number.

### TechnicalSupport

The `TechnicalSupport` class manages technical support operations for the ATM.

#### Methods

- `void reportIssue(const string& issue) const`
  - Reports an issue.
- `void scheduleMaintenance(const string& date) const`
  - Schedules maintenance on a specified date.
- `void checkATMStatus() const`
  - Checks the status of the ATM.

### Transaction

The `Transaction` class is an abstract base class for transactions.

#### Methods

- `virtual void execute() = 0`
  - Pure virtual method to execute the transaction.

### WithdrawTransaction

The `WithdrawTransaction` class handles withdrawal operations.

#### Attributes

- `atm` (ATM&): Reference to the ATM.
- `amount` (double): Amount to withdraw.

#### Methods

- `WithdrawTransaction(ATM& atm, double amount)`
  - Constructor that initializes the transaction with an ATM reference and amount.
- `void execute() override`
  - Executes the withdrawal transaction.

### DepositTransaction

The `DepositTransaction` class handles deposit operations.

#### Attributes

- `atm` (ATM&): Reference to the ATM.
- `amount` (double): Amount to deposit.

#### Methods

- `DepositTransaction(ATM& atm, double amount)`
  - Constructor that initializes the transaction with an ATM reference and amount.
- `void execute() override`
  - Executes the deposit transaction.

## Constants

### ATMConstants

The `ATMConstants` namespace contains various constants used in the ATM system.

#### Constants

- `const string TECH_PASSWORD = "tech123"`
- `const string CARD_INSERT_PROMPT = "Please enter your PIN:"`
- `const string PIN_VERIFIED_MESSAGE = "PIN Verified. Choose an option: 1) Withdraw 2) Deposit 3) Transfer 4) Change PIN"`
- `const string ISSUE_REPORTED_MESSAGE = "Issue reported."`
- `const string STATUS_CHECKED_MESSAGE = "ATM status checked."`
- `const string DEPOSIT_SUCCESS_MESSAGE = "Deposit successful."`
- `const string INSUFFICIENT_FUNDS_MESSAGE = "Insufficient funds."`
- `const string WITHDRAW_SUCCESS_MESSAGE = "Withdrawal successful."`
- `const string INVALID_PIN_MESSAGE = "Invalid PIN. Please try again."`
- `const string INVALID_CARD_MESSAGE = "Invalid card. Please try again."`
- `const string MAINTENANCE_SCHEDULED_MESSAGE = "Maintenance scheduled on: "`
- `const string VAULT_INSUFFICIENT_FUNDS_MESSAGE = "Vault has insufficient funds."`

---

This API documentation should provide a clear and comprehensive guide to the ATM interface project. If you need any further details or adjustments, feel free to let me know!
