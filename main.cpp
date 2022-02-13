// iterator pattern

#include <iostream>

using namespace std;

class ConcreteIterator;

struct Node{
    int data;
    Node * next;

    Node(){
        this->next = nullptr;
    }
    Node(int data, Node * c){
        this->data = data;
        this->next = c;
    }
};

//template <class T>
class Iterator{
    virtual ConcreteIterator& operator++() = 0;
    virtual ConcreteIterator operator++(int) = 0;
    virtual int operator*() = 0;
    virtual bool operator==(ConcreteIterator * iterator) = 0;
    virtual bool operator!=(ConcreteIterator * iterator) = 0;
    virtual bool hasMore() = 0;
};

class ConcreteIterator: public Iterator{
    Node * ptr;

public:
    ConcreteIterator(Node * head){
        this->ptr = head;
    }

    //pre increment
    ConcreteIterator& operator++() override{
        ptr = ptr->next;
        return *this;
    }

    // post increment
    ConcreteIterator operator++(int) override{
        ConcreteIterator ret = *this;
        ++* (this);
        return ret;
    }

    int operator*() override{
        return ptr->data;
    }

    bool hasMore() override{
        if(ptr->next == nullptr){
            return false;
        }
        return true;
    }

    bool operator==(ConcreteIterator * t) override{
        if(t->ptr->data == this->ptr->data)
            return true;
        return false;
    }

    bool operator!=(ConcreteIterator * t) override{
        if(t->ptr->data != this->ptr->data)
            return true;
        return false;
    }
};

//template <class T>
class IterableCollection{
    Node * head;
public:
    IterableCollection(Node * head){
        this->head = head;
    }

    ConcreteIterator createIterator(){
       return ConcreteIterator(head);
    }

    Node * getHead(){
        return this->head;
    }
};



int main() {

    Node * head = new Node(5, new Node(6, new Node()));
    IterableCollection * t = new IterableCollection(head);
    ConcreteIterator t2 = t->createIterator();
    int num = *t2;
    cout << num;
    t2++;
    cout << *t2;



    return 0;
}
