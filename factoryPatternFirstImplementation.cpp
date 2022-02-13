// factory pattern - basic implementation

#include <iostream>

using namespace std;

class Product{
public:
    virtual void myProduct() = 0;
};

class ProductA: public Product{
public:
    void myProduct() override{
        std::cout << "I'm product A\n";
    }
};

class ProductB: public Product{
public:
    void myProduct() override{
        std::cout << "I'm product B\n";
    }
};

class ProductC: public Product{
public:
    void myProduct() override{
        std::cout << "I'm product C\n";
    }
};

class Creator{
public:
    virtual Product * factoryMethod() = 0;
};

class CreatorProductA:Creator{
public:
    Product * factoryMethod() override{
        return new ProductA();
    }
};

class CreatorProductB:Creator{
public:
    Product * factoryMethod() override{
        return new ProductB();
    }
};

class CreatorProductC:Creator{
public:
    Product * factoryMethod() override{
        return new ProductC();
    }
};

int main() {
    Product * a = CreatorProductA().factoryMethod();
    a->myProduct();
    Product * b = CreatorProductB().factoryMethod();
    b->myProduct();
    Product * c = CreatorProductC().factoryMethod();
    c->myProduct();

    return 0;
}
