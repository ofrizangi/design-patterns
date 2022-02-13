// adapter class

#include <iostream>

using namespace std;

template <class T>
class Sorter{
protected:
    virtual void sort(T * arr, int length)=0;
};


template <class T>
class BubbleSorter:public Sorter<T>{
protected:
    virtual void sort(T * arr, int length){
        for(int j=0; j<length; j++){
            for(int i=0; i< length - j - 1; i++){
                if(arr[i] < arr[i+1]){
                    swap(&arr[i] , &arr[i+1]);
                }
            }
        }
    }
    void swap(T * a, T * b){
        T temp = *a;
        *a = *b;
        *b= temp;
    }
};


class Task{
public:
    virtual void doTask() = 0;
};

template <class T>
class BubbleSorterTask: public Task, public BubbleSorter<T>{

    T * arr;
    int length;
public:
    BubbleSorterTask<T>(T * arr, int length){
        this->arr = arr;
        this->length = length;
    }
    void doTask() override {
        this->sort(this->arr, this->length);
        for ( int i=0; i<length; i++){
            cout << arr[i] << " ";
        }
    }
};



int main() {
    int arr[10] = {5,4,3,2,6,7,8,9, 99, 1};
    BubbleSorterTask<int> bubbleSorterTask(arr, 10);
    bubbleSorterTask.doTask();


    return 0;
}
