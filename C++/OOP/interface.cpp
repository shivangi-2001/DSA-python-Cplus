// Create interface Printable
// Method:
// print()
// Implement it in:
// Document
// Photo
#include<iostream>
#include<string>
using namespace std;

class Printable{
protected:
    string message;
public:
    Printable(string message): message(message){
        cout << message << " is a created." << endl;
    };
    virtual void print() = 0;
    virtual ~Printable(){};
};

class Photo: public Printable{
    public:
    Photo() : Printable("Photo"){};
    void print() override{
        cout << "Photo is printing" << endl;
    }
};

class Document: public Printable{
    public:
    Document() : Printable("Document"){};
    void print() override{
        cout << "Document is printing" << endl;
    }
};

int main(){
    Printable* p1 = new Photo();
    p1->print();
    Printable* d1 = new Document();
    d1->print();

    delete p1;
    delete d1;
    return 0;
}