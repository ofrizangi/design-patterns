// composite pattern

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class CycleException: public exception{
};

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

vector<Employee *> hasManager;
//composite
class Manager: public Employee{
    vector<Employee *> * v;

private:

    bool find(Employee * e){
        for(vector<Employee *>:: iterator it = hasManager.begin(); it!= hasManager.end(); it++){
            if(*it == e){
                return true;
            }
        }
        return false;
    }

    bool ifHisMyManager(Employee * employee){
        Manager * m = dynamic_cast<Manager *>(employee);
        // if the dynamic casting didn't return null he is a manager
        if(m!= nullptr){
            if(this == employee)
                return true;
            for(vector<Employee *>:: iterator it = m->v->begin(); it!= m->v->end(); it++){
                if( ifHisMyManager(*it)){
                    return true;
                }
            }
        }
        return false;
    }

public:
    Manager(string name, int age) : Employee(name, age){
        this->v = new vector<Employee *>();
    }

    void addEmployee(Employee * employee) override{
        if(this == employee || ifHisMyManager(employee) || find(employee) ){
            throw CycleException();
        }
        this->v->push_back(employee);
        hasManager.push_back(employee);
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
    Manager* m0=new Manager("alice" , 22);
    Manager* m1=new Manager("alice" , 22);
    Manager* m2=new Manager("alice" , 22);
    Employee* e0=new Engineer("alice" , 22);
    Employee* e1=new Engineer("alice" , 22);
    Employee* e2=new Engineer("alice" , 22);
    Employee* e3=new Engineer("alice" , 22);
    m0->addEmployee(e0);

    m0->addEmployee(m1);
    m1->addEmployee(e1);
    m1->addEmployee(e2);
    m1->addEmployee(m2);
    m2->addEmployee(e3);
    try{
        m1->addEmployee(e0);
    }catch(CycleException e){
        cout<<"catch 1"<<endl;
    }
    try{
        m2->addEmployee(m0);
    }catch(CycleException e){cout<<"catch 2"<<endl;}
    try{
        m1->addEmployee(m1);
    }catch(CycleException e){ cout<<"catch 3"<<endl;}
    delete m0;






//    Manager * m1 = new Manager("alice" , 35);
//    Engineer * e1 = new Engineer("bob" , 31);
//    Manager * m2 = new Manager("dave", 34);
//    Engineer * e2 = new Engineer("charlie" , 25);
//
//    m1->addEmployee(e1);
//    m1->addEmployee(m2);
//    m2->addEmployee(e2);
////    m1->removeEmployee(e1);
//
//    m1->work();
//    m2->work();



    return 0;
}
