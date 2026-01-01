# Banking System in C++

##  Overview
This project is a simple **Bank Management System** implemented in C++ using **file handling**. It allows users to create and manage bank accounts, perform deposits and withdrawals, update balances, authenticate users, and check account details. All account data is stored in a binary file (`Bank.dat`).

The program demonstrates:
- Object-Oriented Programming (OOP) concepts (class `Account`)
- File handling (`ifstream`, `ofstream`, `fstream`)
- Basic CRUD operations on account records

---

##  Features
- **Create Account**: Generates a random account number, stores customer name and opening balance.
- **Display Accounts**: Shows details of all accounts stored in the file.
- **Search Account**: Finds and displays details of a specific account by account number.
- **Update Balance**: Updates the opening balance of a specific account.
- **Close Account**: Deletes an account record from the file.
- **User Authentication**: Verifies account number with a fixed password (`user_123#`).
- **Deposit Money**: Adds funds to an account and updates the balance.
- **Withdraw Money**: Withdraws funds with checks for minimum balance (`>= 1000`).
- **Check Balance**: Displays the current balance of a specific account.
- **Exit**: Terminates the program.

---

##  File Structure
- **Bank.dat** → Binary file storing account records.
- **new.dat** → Temporary file used during account deletion.

---
# Menu Options
1. Create Account
2. Display All The Accounts
3. Search Specific Account
4. Update Specific Account Opening Balance
5. Close Account
6. User Authentication
7. Deposit
8. Withdraw
9. Check Bank Balance
10. EXIT

---

Important Notes-
- Account numbers are randomly generated between 1 and 500.
- Minimum balance requirement: 1000 units.
- Password for authentication.
- Data is stored in binary format for efficiency.
- On program start, Bank.dat is removed to ensure a fresh run (you may remove this line if persistence is required).
