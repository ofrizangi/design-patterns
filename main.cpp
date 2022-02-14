// template pattern

// disadvantage - for every template method we will need to build a new abstract class with new
// concrete classes that will have to implement the same methods again

#include <iostream>


class AbstractClass {

protected:
    virtual void operation1() = 0;
    virtual void operation2() = 0;

public:
    void templateMethod(){
        operation1();
        operation2();
    }
};


class ConcreteClass1: public AbstractClass {


    void operation1() override{
        std::cout << "operation 1 from ConcreteClass1\n";
    };
    void operation2() override{
        std::cout << "operation 2 from ConcreteClass1\n";
    }
};

class ConcreteClass2: public AbstractClass {


    void operation1() override{
        std::cout << "operation 1 from ConcreteClass2\n";
    };
    void operation2() override{
        std::cout << "operation 2 from ConcreteClass2\n";
    }
};


int main() {
    AbstractClass * a = new ConcreteClass1();
    a->templateMethod();
    a = new ConcreteClass2();
    a->templateMethod();

    return 0;
}
