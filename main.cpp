// object adapter pattern

#include <iostream>

using namespace std;

// in general we will prefer to use vector and iterators, but just for the basic design



template <class T>
class Sorter{
public:
    virtual void sort(T * arr, int length)=0;
};


template <class T>
class BubbleSorter:public Sorter<T>{

    void swap(T * a, T * b){
        T temp = *a;
        *a = *b;
        *b= temp;
    }
public:
    virtual void sort(T * arr, int length){
        for(int j=0; j<length; j++){
            for(int i=0; i< length - j - 1; i++){
                if(arr[i] < arr[i+1]){
                    this->swap(&arr[i] , &arr[i+1]);
                }
            }
        }
    }

};


class Task{
public:
    virtual void doTask() = 0;
};

template < class T>
class SorterTask: public Task{
    Sorter<T> * mySorter;
    T * arr;
    int length;
public:
    SorterTask<T>(Sorter<T> * sorter, T * arr, int length){
        this->mySorter = sorter;
        this->arr = arr;
        this->length = length;
    }

public:
    void doTask() override{
        this->mySorter->sort(arr, length);
        for(int i=0; i<length;i++){
            cout << arr[i] << " ";
        }
    }
};



int main() {
    int arr[10] = {5,4,3,2,6,7,8,9, 99, 1};
    SorterTask<int> sorterTask(new BubbleSorter<int>() , arr, 10);
    sorterTask.doTask();

    return 0;
}