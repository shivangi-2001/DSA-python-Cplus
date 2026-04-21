// Shape Hierarchy
// Base class: Shape
// Method: calculateArea()
// Derived classes:
// Circle
// Rectangle
// Triangle
// Override calculateArea() in each class.

#include<iostream>
using namespace std;

class Shape{
    public:
    virtual void calculateArea(){
    
    }
};

class Circle: public Shape{
    public:
    int radius;

    Circle(int radius): radius(radius){};

    void calculateArea() override {
        cout << "Circle area: " <<(22/7)*radius*radius << endl;
    }
};

class Triangle: public Shape{
    public:
    int height;
    int base;

    Triangle(int height, int base): height(height), base(base){};

    void calculateArea() override {
        cout << "Triangle area: " << (1/sqrt(3))*height*base << endl;
    }
};

class Rectangle: public Shape{
    public:
    int length;
    int base;

    Rectangle(int length, int base): length(length), base(base){};

    void calculateArea() override {
        cout << "Rectangle area: " << length*base << endl;
    }
};

int main(){
    Shape* c = new Circle(3);
    Shape* t = new Triangle(3, 10);
    Shape* r = new Rectangle(10, 10);

    c->calculateArea();
    t->calculateArea();
    r->calculateArea();
    return 0;
}