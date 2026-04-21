// Method Overriding
// Base class: Payment
// Method: pay()
// Derived:
// CreditCardPayment
// UPIPayment
// CashPayment
// Each class prints different message in pay().

#include<iostream>
using namespace std;

class Payment{
    public:
    virtual ~Payment(){};
    virtual void pay(string& message) = 0;
};

class CreditCardPayment: public Payment{
    public:
    void pay(string& message) override{
        cout << "Credit card payment " <<  message << endl;
    }
};

class UPIPayment: public Payment{
    public:
    void pay(string& message) override{
        cout << "UPI Payment " <<  message << endl;
    }
};

class CashPayment: public Payment{
    public:
    void pay(string& message) override{
        cout << "Cash Payment " <<  message << endl;
    }
};

int main(){
    Payment* c1 = new CreditCardPayment();
    string ans = "Hello world";
    c1-> pay(ans);

    Payment* c3 = new CashPayment();
    string ans2 = "Hello world";
    c3-> pay(ans2);
    return 0;
}