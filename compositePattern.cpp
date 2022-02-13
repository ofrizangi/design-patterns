// composite pattern

#include <iostream>
#include <vector>

using namespace std;

// we can't do employee abstract because of the vector (doesn't let putting abstract objects),
// maybe try to implement in a different way by abstract
// component
class Employee{
protected:
    string name;
    int age;
public:
    Employee(string name, int age){
        this->name = name;
        this->age = age;
    }
    virtual void work(){}

    virtual void addEmployee(Employee * employee) {}

    virtual void removeEmployee(Employee * employee) {}

    string getName(){
        return this->name;
    }

    bool operator ==(Employee e) const{
        if(this->name == e.name && this->age == e.age)
            return true;
        return false;
    }
};


// leaf
class Engineer: public Employee{
public:
    Engineer(string name, int age) : Employee(name, age){}
    virtual void work() override{
        cout << this->name << " is working\n";
    };
};


//composite
class Manager: public Employee{
    vector<Employee *> * v;

public:
    Manager(string name, int age) : Employee(name, age){
        this->v = new vector<Employee *>();
    }

    void addEmployee(Employee * employee) override{
        this->v->push_back(employee);
    }

    void removeEmployee(Employee * employee) override{
        vector<Employee *>:: iterator it;
        for(it = v->begin(); it != v->end(); it++){
            Employee * e = *it;
            if(e == employee){
                this->v->erase(it);
                break;
            }
        }
    }

    void work() override{
        cout << this->getName() << " is working\n";
        vector<Employee *>:: iterator it;
        for(it = v->begin(); it != v->end(); it++){
            Employee * e = *it;
            e->work();
        }
    }

    ~Manager(){
        delete v;
    }
};






int main() {
    Manager * m1 = new Manager("alice" , 35);
    Engineer * e1 = new Engineer("bob" , 31);
    Manager * m2 = new Manager("dave", 34);
    Engineer * e2 = new Engineer("charlie" , 25);

    m1->addEmployee(e1);
    m1->addEmployee(m2);
    m2->addEmployee(e2);
//    m1->removeEmployee(e1);

    m1->work();
//    m2->work();



    return 0;
}
