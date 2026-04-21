#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Product{
    private:
        string name;
        double price;

    public:
        Product(const string& name, const double& price): name(name), price(price){};
        double getPrice() {
            return price;
        }
};

class Catalog{
    private:
        vector<Product*> products;

    public:
        void addProduct(Product* product)  {
            for(auto* p: products) if(p==product) return;
            products.push_back(product);
        };
        Product* findByName(string name){
            // return matching product
        }

};

class Cart{
    private:
        vector<Product*> products;
    public:
        void addProduct(Product* product)  {
            for(auto* p: products) if(p==product) return;
            products.push_back(product);
        };
        void clearCart() {
            while(!products.empty()){
                products.pop_back();
            }
        }
        int getTotal(){

        }
};

class Customer{
    private:
    string name;
    Cart* cart = nullptr;

    public:
    void checkout(){
        cout <<  endl;
    }
};

int main() {
    Product laptop("Laptop", 999.99);
    Product mouse("Mouse", 29.99);
    Product keyboard("Keyboard", 79.99);

    Catalog catalog;
    catalog.addProduct(&laptop);
    catalog.addProduct(&mouse);
    catalog.addProduct(&keyboard);

    Cart cart1, cart2;
    Customer alice("Alice", &cart1);
    Customer bob("Bob", &cart2);

    cart1.addItem(&laptop);
    cart1.addItem(&mouse);
    cart2.addItem(&laptop);
    cart2.addItem(&keyboard);

    cout << "Alice's cart: " << cart1.getItemCount() << " items, $" << cart1.getTotal() << endl;
    cout << "Bob's cart: " << cart2.getItemCount() << " items, $" << cart2.getTotal() << endl;

    alice.checkout();

    cout << "Catalog still has " << catalog.getProductCount() << " products" << endl;
    cout << "Bob's cart still has " << cart2.getItemCount() << " items" << endl;
    cout << "Laptop still exists: " << laptop.getName() << endl;

    return 0;
}