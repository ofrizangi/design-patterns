// interpreter pattern

#include <iostream>

// abstract expression
class Expression{
protected:
    int num;
    Expression(int num){
        this->num = num;
    }

//    friend int operator+(const Expression & e1, const Expression & e2);
//    friend int operator-(const Expression & e1, const Expression & e2);

public:
    virtual int interpret() = 0;
};

// terminal expression
class NumNode: public Expression{
public:
    NumNode(int num): Expression(num){}
    int interpret() override{
        return this->num;
    }
};

// non terminal expression
class BinaryNode: public Expression{
protected:
    Expression * exp1;
    Expression * exp2;
public:
    BinaryNode(Expression * exp1, Expression * exp2): Expression(num){
        this->exp1 = exp1;
        this->exp2 = exp2;
    }
};

class Plus: public BinaryNode{
public:
    Plus(Expression * exp1, Expression * exp2): BinaryNode(exp1, exp2){}

    int interpret() override{
       return exp1->interpret() + exp2->interpret();
    }
};

//int operator+(const Expression & e1, const Expression & e2){
//    return e1.num + e2.num;
//}
//int operator-(const Expression & e1, const Expression & e2){
//    return e1.num - e2.num;
//}

class Minus: public BinaryNode{
public:
    Minus(Expression * exp1, Expression * exp2): BinaryNode(exp1, exp2){}

    int interpret() override{
        return exp1->interpret() - exp2->interpret();
    }
};


int main() {

    Expression * e = new Minus(new NumNode(5), new Plus(new NumNode(8) , new NumNode(1)) );
    std::cout << e->interpret();


    return 0;
}
