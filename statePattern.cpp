// state pattern

#include <iostream>

using namespace std;

// State class
class Health{
public:
    virtual void move () = 0;
};

class Healthy: public Health{
    void move() override{
        cout << "I'm moving today";
    }
};

class Faulty: public Health{
    void move() override{
        cout << "I'm sleeping today";
    }
};


// context class
class Context{
    Health * s;
public:
    Context(Health * s){
        this->s = s;
    }

    void Request(){
        this->s->move();
    }
};


int main() {
    Health * s = new Healthy();
    Health * s2 = new Faulty();
    Context * c = new Context(s2);
    c->Request();
    return 0;
}
