// decorator patten
#include <iostream>
using namespace std;


// abstract class
class IceCream{
public:
    virtual void make () = 0;
};


// concrete component
class SimpleIceCream: public IceCream{
    void make() override{
        cout << "simple ice cream with: ";
    }
};

// decorator
class IceCreamDecorator: public IceCream{
    IceCream * cream;
public:
    // getting a decorator or a concrete component in the constructor
    IceCreamDecorator(IceCream * cream){
        this->cream =cream;
    }
    void make() override{
        cream->make();
    }
};

// some different decorators
class WithChocolate: public IceCreamDecorator{
public:
    WithChocolate(IceCream * cream): IceCreamDecorator(cream){
    }
    void make() override{
        IceCreamDecorator::make();
        cout << "chocolate ";
    }
};

class WithNuts: public IceCreamDecorator{
public:
    WithNuts(IceCream * cream): IceCreamDecorator(cream){
    }
    void make() override{
        IceCreamDecorator::make();
        cout << "nuts ";
    }
};

class WithFruits: public IceCreamDecorator{
public:
    WithFruits(IceCream * cream): IceCreamDecorator(cream){
    }
    void make() override{
        IceCreamDecorator::make();
        cout << "fruits ";
    }
};



int main() {
    IceCream * c1 = new WithChocolate(new WithFruits(new WithNuts(new SimpleIceCream)));
    c1->make();
    cout << '\n';
    IceCream * c2 = new WithChocolate(new WithChocolate(new WithChocolate(new WithFruits(new SimpleIceCream))));
    c2->make();
    return 0;
}
