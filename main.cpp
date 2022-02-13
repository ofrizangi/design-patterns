// fcade pattern

#include <iostream>

using namespace std;

// some subsystems in a complex library our client want to use

class SubSystem1{
public:
    std::string methodA(){
        return "hey";
    }

    std::string methodB(){
        return "billy";
    }
    std::string methodC(){
        return "bye bye";
    }
};

class SubSystem2{
public:
    std::string methodA(){
        return "so";
    }

    std::string methodB(){
        return "what";
    }
    std::string methodC(){
        return "bye bye";
    }
};


// fcade class - contains the relevent subSystem classes and operate by calling them.
// the client uses only the fcade to do does operation
// low coupling

class Fcade{
    SubSystem1 * s1;
    SubSystem2 * s2;

public:
    Fcade(){
        this->s1 = new SubSystem1();
        this->s2 = new SubSystem2();
    }

    void operateAllMethods(){
        cout << this->s1->methodA() << " " << this->s2->methodA() << "\n";
        cout << this->s1->methodB() << " " << this->s2->methodB() << "\n";
        cout << this->s1->methodC() << " " << this->s2->methodC() << "\n";
    }
    ~Fcade(){
        delete s1;
        delete s2;
    }

};





int main() {
    // lets say the main is the client, so it will:


    Fcade * f = new Fcade();
    f->operateAllMethods();
    delete f;

    return 0;
}
