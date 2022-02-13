#include <iostream>

using namespace std;
class Product{
private:
    static Product * instance;
    Product(){}

public:
    static Product * getInstance();
    void print(){
        std::cout << "I'm the only instance\n";
    }
};

// we write here the class the static members are in and the value they return / contain.
Product * Product::instance = NULL;
Product * Product::getInstance() {
    if(instance == NULL){
        instance = new Product();
        cout << "creating a new instance\n";
        return instance;
    }
    cout << "giving you the old instance\n";
    return instance;
}

int main() {

    Product * p = Product::getInstance();
    p->print();
    Product * p1 = Product::getInstance();
    p1->print();
    return 0;
}
