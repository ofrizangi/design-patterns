// flyweight pattern

#include <iostream>
#include <map>
using namespace std;

struct SharedState{
    string type;
    string condition;
public:
    SharedState(string type, string condition){
        this->type = type;
        this->condition = condition;
    }
    string getType(){
        return this->type;
    }
    string getCondition(){
        return this->condition;
    }
};

// flyweight
// can do different classes that will implement this class and add behavories - their shared state will remain the same
class Character{
   SharedState * sharedState;
public:
   Character(SharedState * s){
       this->sharedState = s;
   }

   void paint (int i, int j){
       cout << "new " << sharedState->type << " is in the board in position: " << i << "," << j << endl;
   }
};

// flyweight factory
class CharacterFactory{
    map<SharedState *, Character *> * m;
public:
    CharacterFactory(){
        this->m = new map<SharedState *, Character *>();
    }

    Character * getCharacter(SharedState * s){
        map<SharedState *, Character *>:: iterator it;
        for(it = m->begin(); it != m->end(); it++){
            if(it->first->getCondition() == s->getCondition() && it->first->getType() == s->getType()){
                cout << "returning an existing character\n";
                return it->second;
            }
        }
        Character * c = new Character(s);
        m->insert(pair<SharedState *, Character *>(s,c));
        cout << "returning a new character\n";
        return c;
    }


    ~CharacterFactory(){
        delete m;
    }

};


int main() {
    CharacterFactory * factory= new CharacterFactory();
    SharedState * s = new SharedState("soldier", "healthy");
    SharedState * s2 = new SharedState("tank", "wealthy");

    Character * c1 = factory->getCharacter(s);
    c1->paint(1,2);

    Character * c2 = factory->getCharacter(s2);
    c2->paint(3,4);

    Character * c3 =  factory->getCharacter(s);
    c3->paint(7,8);


    return 0;
}
