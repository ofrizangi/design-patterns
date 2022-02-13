// bridge pattern

#include <iostream>
#include <string>

using namespace std;


// implementation

class Move{
public:
    virtual void myMove() = 0;
};

class Walk: public Move{
    void myMove() override{
        cout << "i'm walking\n";
    }
};

class Swim: public Move{
    void myMove() override{
        cout << "i'm swimming\n";
    }
};

class Fly: public Move{
    void myMove() override{
        cout << "i'm flying\n";
    }
};


// abstraction

class Animal{
protected:
    Move * move;

public:
    Animal (Move * move) {
        this->move = move;
    }

    virtual void myNature() = 0;
};

class Person: public Animal{
public:
    Person(Move * m): Animal(m){}

    void myNature() override{
        cout << "I'm a person and ";
        move->myMove();
    }
};

class Bird: public Animal{
public:
    Bird(Move * m): Animal(m){}

    void myNature() override{
        cout << "I'm a bird and ";
        move->myMove();
    }
};

class Fish: public Animal{
public:
    Fish(Move * m): Animal(m){}

    void myNature() override{
        cout << "I'm a fish and ";
        move->myMove();
    }
};



int main() {

    Animal * a1 = new Person(new Walk());
    a1->myNature();
    Animal * a2 = new Bird(new Fly());
    a2->myNature();
    Animal * a3 = new Fish(new Swim());
    a3->myNature();
    Animal * a4 = new Person(new Swim());
    a4->myNature();


    return 0;
}
