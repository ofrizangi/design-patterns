#include <iostream>
#include <map>

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

map<string, Worker *> * mapWorkers;

class WorkerFactory{

private:
    // like the first implmintetion

//    class Creator{
//        virtual Worker * factoryMethod() = 0;
//    };
//    class AdminCreator: public Creator{
//        Worker * factoryMethod() override{
//            return new Admin();
//        }
//    };
//    class TACreator: public Creator{
//        Worker * factoryMethod() override{
//            return new TA();
//        }
//    };
//    class LecturerCreator: public Creator{
//        Worker * factoryMethod() override{
//            return new Lecturer();
//        }
//    };

// takes o(n) memory, but o(1) to return an object
public:
    WorkerFactory(){
        mapWorkers = new map<string, Worker *>();
        mapWorkers->insert(pair<string, Worker *> ("lecturer" ,new Lecturer() ));
        mapWorkers->insert(pair<string, Worker *> ("admin" ,new Admin() ));
        mapWorkers->insert(pair<string, Worker *> ("ta" ,new TA() ));
    }

    Worker * createWorker(const string & id){
        return mapWorkers->find(id)->second;
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
