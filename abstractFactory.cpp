#include <iostream>

using namespace std;

//abstract product 1
class Sofa{
public:
    virtual string sofaType() = 0;
    virtual ~Sofa() = default;
};

// concrete products
class ModernSofa:public Sofa{
    string sofaType() override{
        return "modern sofa";
    }
};
class OldSofa:public Sofa{
    string sofaType() override{
        return "old sofa";
    }
};

//abstract product 2
class Chair{
public:
    virtual string chairType() = 0;
    virtual ~Chair() = default;
};

// concrete products
class ModernChair:public Chair{
public:
    string chairType() override{
        return "modern chair";
    }
};
class OldChair:public Chair{
public:
    string chairType() override{
        return "old chair";
    }
};


// abstract factory
class FurnitureFactory{
public:
public:
    virtual Chair* createChair() = 0;
    virtual Sofa* createSofa() = 0;
};

// concrete factory 1
class ModernFurnitureFactory: public FurnitureFactory{
public:
    Chair * createChair() override{
        return new ModernChair();
    }
    Sofa * createSofa() override{
        return new ModernSofa();
    }
};

class OldFurnitureFactory: public FurnitureFactory{
public:
    Chair * createChair() override{
        return new OldChair();
    }
    Sofa * createSofa() override{
        return new OldSofa();
    }
};



int main() {
    Chair * a = OldFurnitureFactory().createChair();
    Sofa * b  = OldFurnitureFactory().createSofa();
    Chair * a2 = ModernFurnitureFactory().createChair();
    Sofa * b2 = ModernFurnitureFactory().createSofa();
    cout << a->chairType() << " " << b->sofaType() << endl;
    cout << a2->chairType() << " " << b2->sofaType() << endl;
    delete a;
    delete b;
    delete a2;
    delete b2;



//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
