// Vehicle System
// Create a base class Vehicle:
// brand
// speed
// start()
// stop()
// Create subclasses:
// Car
// Bike
// Add specific method:
// Car → openTrunk()
// Bike → kickStart()

#include<iostream>
using namespace std;

class Vehicle{
    protected:
    string brand;
    int speed;
    public:
    Vehicle(string brand, int speed){
        this->brand=brand;
        this->speed=speed;
    }
    
    virtual void start(){
        cout << brand << " is start with speed " << speed << endl;
    }

    virtual void stop(){
        cout << brand << " is stop at speed " << speed << endl;
    }

    virtual ~Vehicle(){
        cout << "vehicle is deleted" << endl;
    }
};

class Car: public Vehicle {
    public:
    Car(string brand, int speed): Vehicle(brand, speed) {}
    void openTrunk(){
       cout <<  "Trunk is open" << endl;
    }

    void start() override{
        cout << "Car of " << brand << " is start with speed " << speed << endl;
    }
};

class Bike: public Vehicle {
    public:
    Bike(string brand, int speed): Vehicle(brand, speed) {}
    void kickStart(){
       cout <<  "Kickstart" << endl;
    }
    
    void stop() override {
        cout << "Bike of " << brand << " is stop at speed " << speed << endl;
    }
};

int main(){
    Vehicle* v1 = new Car("Toyota", 120);
    Vehicle* v2 = new Bike("Honda", 80);

    v1->start();  // polymorphism
    v1->stop();
    v2->stop();   // polymorphism

    delete v1;
    return 0;
}