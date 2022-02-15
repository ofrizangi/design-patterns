// prototype + clone - inorder to avoid n classes we use clone methods that will return use a new object

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Worker{
public:
    virtual void whichWorker () = 0;
    virtual Worker* clone() = 0;
    virtual ~Worker() = default;
};

class Admin:public Worker{
public:
    void whichWorker () override{
        cout << "I'm a admin\n";
    }
    Worker * clone() override{
        return new Admin();
    }
    ~Admin() = default;
};

class TA:public Worker{
public:
    void whichWorker () override{
        cout << "I'm a ta\n";
    }
    Worker * clone() override{
        return new TA();
    }
    ~TA() = default;
};

class Lecturer:public Worker{
public:
    void whichWorker () override{
        cout << "I'm a lecturer\n";
    }
    Worker * clone() override{
        cout << "you just made a new lecturer";
        return new Lecturer();
    }
    ~Lecturer() = default;
};


class WorkerFactory{

private:
    map<string,  Worker*> * mapWorkers;


// takes o(n) memory, but o(1) to return an object
public:
    WorkerFactory(){
        mapWorkers = new map<string, Worker *>();
        mapWorkers->insert(pair<string, Worker *> ("lecturer" ,new Lecturer()));
        mapWorkers->insert(pair<string, Worker *> ("admin" ,new Admin() ));
        mapWorkers->insert(pair<string, Worker *> ("ta" ,new TA() ));
    }

    Worker * createWorker(const string & id){
        Worker * c = mapWorkers->find(id)->second;
        return c->clone();
    }

    ~WorkerFactory(){
        map<string, Worker *>:: iterator it;
        for(it = mapWorkers->begin(); it != mapWorkers->end(); it++){
            delete it->second;
        }
    }

};


int main() {
    WorkerFactory * f = new WorkerFactory();
    Worker * a = f->createWorker("lecturer");
    Worker * b = f->createWorker("ta");
    Worker * c = f->createWorker("admin");
    a->whichWorker();
    b->whichWorker();
    c->whichWorker();
    delete f;
    return 0;
}
