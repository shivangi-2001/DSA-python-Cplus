// Method Overloading
// Create a Calculator class:
// add(int, int)
// add(double, double)
// add(int, int, int)

#include<iostream>
using namespace std;
class Add{
    int x1;
    int y1;
    int z1;
    double x2;
    double y2;
    public:
        Add(int x, int y){
            x1=x;
            y1=y;
        };

        Add(double x, double y){
            x2=x;
            y2=y;
        };

        Add(int x, int y, int z){
            x1=x;
            y1=y;
            z1=z;
        };
};

int main(){
    Add A1(2, 3);
    Add  A2(2.3, 1.1);
    return 0;
};