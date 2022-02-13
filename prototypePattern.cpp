#include <iostream>
#include <vector>

using namespace std;

class Shape{
    float x,y;
    string color;
public:
    Shape(string color, float x, float y){
        this->color = color;
        this->x = x;
        this->y = y;
    }
    virtual Shape* clone () = 0;
};

class Circle: public Shape{
    float radius;
public:
    Circle(string color, float  radius, float x, float y): Shape(color, x,y){
        this->radius = radius;
    }

    Shape * clone() override{
        cout << "You just created a knew copy!";
        return new Circle(*this);
    }

};

class Rectangle: public Shape{
    int width;
    int height;
public:
    Rectangle(string color, int width, int height, float x, float y): Shape(color, x,y){
        this->width = width;
        this->height = height;
    }

    Shape * clone() override{
        cout << "You just created a knew copy!";
        return new Rectangle(*this);
    }
};



int main() {
    Circle * circle = new Circle("blue" , 1,1,1);
    Rectangle * rec= new Rectangle("red", 5,8,1,4);
    circle->clone();
    rec->clone();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
