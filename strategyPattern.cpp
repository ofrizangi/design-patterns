// strategy pattern
#include <iostream>

using namespace std;

class Worker{
    int age;
    string name;
public:
    Worker(string name, int age){
        this->name = name;
        this->age = age;
    }

    int getAge(){
        return this->age;
    }

    string getName(){
        return this->name;
    }
};



class Comperator{
public:
    virtual bool compare (Worker worker1, Worker worker2) = 0;
};


class AgeComperator: public Comperator{
    bool compare(Worker worker1, Worker worker2) override{
        if(worker1.getAge() > worker2.getAge())
            return true;
        return false;
    }
};

class NameComperator: public Comperator{
//    AgeComperator(Worker worker1): Comperator(worker1){}

    bool compare(Worker worker1, Worker worker2) override{
        if(worker1.getName() > worker2.getName())
            return true;
        return false;
    }
};




class Sorter{
    Comperator * comperator;
public:
    Sorter(Comperator * comperator){
        this->comperator = comperator;
    }

    void sort(Worker ** arr, int length){
        for(int i=0;i<length;i++){
            for(int j=0;j<length-i-1;j++){
                if(comperator->compare(*arr[j], *arr[j+1])){
                    Swap(arr[j] , arr[j+1]);
                }
            }
        }
    }

private:
    void Swap(Worker * work1, Worker * work2){
        Worker temp = *work1;
        *work1 = *work2;
        *work2 = temp;
    }

};









int main() {
    Worker * workers[3];

    Worker * w1 = new Worker("ofri" , 22);

    Worker * w2 = new Worker("dandan" , 120);

    Worker * w3 = new Worker("num" , 99);

    workers[0] = w1;
    workers[1] = w2;
    workers[2] = w3;
    Comperator * comperator = new AgeComperator();
    Sorter * sorter = new Sorter(comperator);
    sorter->sort(workers, 3);
    cout << workers[0]->getAge() << " " << workers[1]->getAge() << " " << workers[2]->getAge();

    return 0;
}
