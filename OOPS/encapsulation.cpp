/*
    Encapsulation in C++ is achieved by combining two core concepts: 
        * Data Hiding (using access specifiers)
        * Data Bundling (grouping data and methods into a single unit).
        
        It is achieved using `access specifiers` and `getters and setters`
*/
#include <iostream>

using namespace std;

class BankAccount {
private:
    double balance; // Private data member

public:
    // Public method to initialize balance
    // BankAccount(double initialBalance) : balance(initialBalance) {} // Parameterized Constructor that uses a Member Initializer List
    BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Public method to get the current balance
    double getBalance() const {
        return balance;
    }

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Public method to withdraw money
    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

int main() {

    BankAccount myAccount(500.0);
    cout << "Initial Balance: $" << myAccount.getBalance() << endl;

    myAccount.deposit(150.50);
    cout << "New Balance: $" << myAccount.getBalance() << endl;

    if (myAccount.withdraw(200.00)) {
        cout << "Withdrawal successful!" << endl;
    } else {
        cout << "Withdrawal failed! Insufficient funds." << endl;
    }

    cout << "Current Balance: $" << myAccount.getBalance() << endl;

    return 0;
}