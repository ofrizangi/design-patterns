#include <iostream>
#include <vector>
using namespace std;


class Person{
    char * name;
    int age;
public:
    Person(char * name, int age){
        this->name = new char[20];
        this->name = name;
        this->age = age;
    }

    // copy constructor
    Person(const Person & person){
        cout << "copy constructor\n";
        this->name = nullptr;
        *this = person;
    }

    // copy operator
    Person& operator=(const Person& person){
        cout << "copy operator\n";
        if(this != &person){
            if(name != nullptr){
                delete name;
            }
            this->name = new char[20];
            this->age = person.age;
            this->name = person.name;
        }
        return *this;
    }

    Person(Person&& person ) noexcept{
        cout << "move operator\n";
        *this = move(person);
    }

    Person& operator=(Person && person) noexcept{
        cout << "move operator\n";
        if(this!= &person){
            this->name = person.name;
            this->age = person.age;

            person.name = nullptr;
            person.age = 0;
        }
        return *this;
    }
};


int main() {
    Person p1("ofri", 22);
    Person p2(p1);
    p2 = move(p1);
    return 0;
}

