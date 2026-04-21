// Create a Book class:
// title
// author
// price
// isAvailable
// Use constructor to initialize values.
// Create multiple books and print available books only.

#include<iostream>
using namespace std;

class Book{
    private:
        string title;
        string author;
        int price;
        bool isAvailable;
    public:

    Book(string title, string author, int price, bool isAvailable): 
    title(title), author(author), price(price), isAvailable(isAvailable){}

    void display(){
        if(isAvailable) cout << title << " by " << author << " with price " << price << endl;
    }
};

int main(){
    Book b1("ML & AI", "abx", 728, true);

    Book b2("ML & AI - II", "abx", 728, false);

    Book b3("ML & AI - III ", "abx", 728, true);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}