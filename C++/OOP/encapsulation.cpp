// Employee Salary System
// Create an Employee class:
// private salary
// private name
// Provide:
// setSalary()
// getSalary()
// Add validation: salary cannot be negative.

#include<iostream>
using namespace std;

class Employee{
    private:
    string name;
    double salary;

    public:
    
    Employee(const string& name, double salary): name(name) {
        if(salary >= 0){
            this -> salary = salary;
        }else{
            cout << "Invalid salary! Setting to 0." << endl;
            this->salary = 0;
        }
    }

};
int main(){
    Employee E1("abx", 31133);
    Employee E2("gyu", -71826);
    Employee E3("wet", 31133);
    return 0;
}