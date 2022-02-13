// observer pattern
#include <list>
#include <iostream>

using namespace std;

class EventArgs{
    string description;
public:
    EventArgs(){
        this->description = "there was an update";
    }
};

class Observable;

class Observer{
public:
    virtual void update(Observable &o, EventArgs * eventArgs) = 0;
};

// the notifier
class Observable{
    list <Observer *> l1;
public:
    void addToList(Observer * a){
        l1.push_back(a);
    }
    void notify (){
        list<Observer *>:: iterator it;
        for(it = l1.begin(); it!= l1.end(); it++){
            (*it)->update(*this, new EventArgs());
        }
    };
};

// a concrete notifier
// doesn't know all the observers, just calls notify
class MyBirthday: public Observable{
    // the data we are observing on
    int age;
public:
    MyBirthday(int age){
        this->age;
    }
    void setState(int age){
        this->age = age;
        this->notify();
    }

    int getState(){
        return this->age;
    }
};

class ObserverA: public Observer{
    MyBirthday * m;
public:
    ObserverA(MyBirthday * m ){
        this->m = m;
        m->addToList(this);
    }
    void update(Observable &o, EventArgs * eventArgs) override{
        int num = m->getState();
        cout << "happy birthday your " << num << "!\n";
    }
};

class ObserverB: public Observer{
    MyBirthday * m;
public:
    ObserverB(MyBirthday * m ){
        this->m = m;
        m->addToList(this);
    }
    void update(Observable &o, EventArgs * eventArgs) override{
        int num = m->getState();
        cout << "omg your " << num << "!\n";
    }
};


int main() {
    MyBirthday * m = new MyBirthday(22);
    ObserverB * b = new ObserverB(m);
    ObserverA * a = new ObserverA(m);
    m->setState(23);
    m->setState(24);

    return 0;
}
