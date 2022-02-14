#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Worker{
public:
    virtual void whichWorker () = 0;
    virtual ~Worker() = default;
};

class Admin:public Worker{
public:
     void whichWorker () override{
        cout << "I'm a admin\n";
    }
    ~Admin() = default;
};

class TA:public Worker{
public:
    void whichWorker () override{
        cout << "I'm a ta\n";
    }
    ~TA() = default;
};

class Lecturer:public Worker{
public:
    void whichWorker () override{
        cout << "I'm a lecturer\n";
    }
    ~Lecturer() = default;
};


class WorkerFactory{

private:

    class Creator{
    public:
        virtual Worker * factoryMethod() = 0;
    };

    class AdminCreator: public Creator{
        Worker * factoryMethod() override{
            return new Admin();
        }
    };
    class TACreator: public Creator{
        Worker * factoryMethod() override{
            return new TA();
        }
    };
    class LecturerCreator: public Creator{
        Worker * factoryMethod() override{
            return new Lecturer();
        }
    };
    map<string,  Creator*> * mapWorkers;


// takes o(n) memory, but o(1) to return an object
public:
    WorkerFactory(){
        mapWorkers = new map<string, Creator *>();
        mapWorkers->insert(pair<string, Creator *> ("lecturer" ,new LecturerCreator()));
        mapWorkers->insert(pair<string, Creator *> ("admin" ,new AdminCreator() ));
        mapWorkers->insert(pair<string, Creator *> ("ta" ,new TACreator() ));
    }

    Worker * createWorker(const string & id){
        Creator * c = mapWorkers->find(id)->second;
        return c->factoryMethod();
    }

    ~WorkerFactory(){
        map<string, Creator *>:: iterator it;
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
