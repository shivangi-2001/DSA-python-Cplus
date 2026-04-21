#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Course;
class Student;

class Instructor{
    protected:
    string name;
    vector<Course*> courses;

    public:
    Instructor(const string& name): name(name){};
    void addCourse(Course* course);
    string getName() const { return name; };
    vector<Course*> getCourses() { return courses; };
};

class Course{
    protected:
    string name;
    Instructor* intsr = nullptr;
    vector<Student*> students;
    
    public:
    
    Course(const string& name): name(name){};
    
    void setInstructor(Instructor* instructor){
        this->intsr=instructor;
    };
    
    void enrollStudent(Student* student);
    
    string getTitle() { return name;};
    
    vector<Student*> getStudents() {
        return students;
    };

    Instructor* getInstructor(){
        return intsr;
    };
};

class Student{
    protected:
    string name;
    Course* enrolledCourse = nullptr;
    public:
    Student(const string& name): name(name){};
    
    void setEnrolledCourse(Course* course){
        this->enrolledCourse=course;
    };

    string getName() const { return name; };
    
    string getInstructorName() const {
        // TODO: Navigate through enrolledCourse to get the instructor's name
        Instructor* t1 = enrolledCourse->getInstructor();
        return t1->getName();
    }

};

void Instructor::addCourse(Course* course){
    for(auto* c: courses){
        if(c == course){
            return;
        }
    }

    courses.push_back(course);
    course->setInstructor(this);
};

void Course::enrollStudent(Student* student){
    for(auto* c: students){
        if(c == student){
            return;
        }
    }

    students.push_back(student);
    student->setEnrolledCourse(this);
}


int main() {
    Instructor alice("Alice");
    Course dsa("Data Structures");
    Course sysDesign("System Design");

    alice.addCourse(&dsa);
    alice.addCourse(&sysDesign);

    Student bob("Bob");
    Student charlie("Charlie");

    dsa.enrollStudent(&bob);
    dsa.enrollStudent(&charlie);
    sysDesign.enrollStudent(&charlie);

    cout << alice.getName() << "'s courses:" << endl;
    for (auto* c : alice.getCourses())
        cout << "  - " << c->getTitle() << endl;

    cout << "Students in " << dsa.getTitle() << ":" << endl;
    for (auto* s : dsa.getStudents())
        cout << "  - " << s->getName() << endl;

    cout << bob.getName() << "'s instructor: " << bob.getInstructorName() << endl;

    return 0;
}