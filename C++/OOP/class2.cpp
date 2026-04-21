// Create a BankAccount class:
// accountNumber
// accountHolderName
// balance
// Methods:
// deposit(amount)
// withdraw(amount)
// checkBalance()
// Add validation so withdrawal doesn’t exceed balance.

#include<iostream>
#include<string>
using namespace std;

class BankAccount {
    private:
        long accountNumber;
        string accountHolderName;
        long balance;
    public: 
    BankAccount(long accountNumber, string accountHolderName, long balance): 
    accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) {}

    void deposit(long amount){
        if(amount>0) balance += amount;
        cout << "Successfully added amount " << amount <<" total balance: " << balance <<endl;
    }

    void withdraw(long amount){
        if(balance>0 && amount <= balance){
            balance -= amount;
        } 
        cout << "after widthdraw amount balance is: " << balance << endl;
    }
};
int main(){
    BankAccount b1(2781357125387, "shivangi", 26571);

    b1.deposit(784);
    b1.withdraw(2487);
    return 0;
}