#include<iostream>
#include<string>
#include<random>
using namespace std;

class Student {
    public: 
        string name;
        int rollNumber;
        vector<int> marks;

        Student (string name, int rollNumber){
            this -> name = name;
            this -> rollNumber = rollNumber;
            for(int i=0; i<5; i++){
                int rs = rand()%101;
                marks.push_back(rs);
            }
        }

    float calculateAverage(){
        int total = 0;
        for(int i=0; i<marks.size(); i++){
            total += marks[i];
        }
        return static_cast<float> (total)/marks.size();
    }

    void displayDetails(){
        cout << name << " with roll number " << rollNumber << endl;
    }
};

int main(){
    Student s1 = Student("Amar", 20);
    Student* s2 = new Student("Abdul", 21);

    s1.displayDetails();

    cout << s2->calculateAverage() ;

    return 0;
}
// Create a Student class with:
// name
// rollNumber
// marks (array/list)
// Methods:
// calculateAverage()
// displayDetails()
// Create 3 student objects and print their averages.