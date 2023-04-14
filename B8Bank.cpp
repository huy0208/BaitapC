#include <iostream>
#include <string>
using namespace std;
/*
 *Author: Huynh Huy
 *Date: 14/4/2023
 *Description: Tạo một lớp tài khoản ngân hàng với các thuộc tính số tài khoản, tên tài khoản và số dư, và các phương thức để rút, nộp tiền và kiểm tra số dư
trong tài khoản
*/

class BankAccount {
private:
    string accountNumber;
    string accountName;
    double balance;

public:
    BankAccount(string number, string name, double initialBalance) {
        accountNumber = number;
        accountName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << accountNumber << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Error: Insufficient balance in account " << accountNumber << endl;
        }
    }

    void checkBalance() {
        cout << "Account " << accountNumber << " has a balance of " << balance << endl;
    }
};

int main() {
    BankAccount myAccount("123456789", "Huy", 1000.0);
    myAccount.checkBalance();  
    myAccount.deposit(500.0);  
    myAccount.checkBalance();  
    myAccount.withdraw(2000.0);  
    myAccount.withdraw(1000.0);  

    return 0;
}
