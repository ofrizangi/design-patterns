// builder pattern

#include <iostream>

using namespace std;

class Level{
public:
    string character;
    string platform;
    string enemy;
};

class MarioLevel: public Level{
};

class LevelBuilder{
public:
    virtual void setPlatform(string platform) = 0;
    virtual void setCharacter(string charecter) = 0;
    virtual void setEnemy(string enemy) = 0;
    const virtual Level * getLevel() = 0;
};

class MarioLevelBuilder: public LevelBuilder{
    MarioLevel * marioLevel;
public:
    MarioLevelBuilder(){
        this->marioLevel = new MarioLevel();
    }

    void setCharacter(string character) override{
        this->marioLevel->character = character;
    }

    void setPlatform(string platform) override{
        this->marioLevel->platform = platform;
    }
    void setEnemy(string enemy) override{
        this->marioLevel->enemy = enemy;
    }

    const Level * getLevel() override{
        return marioLevel;
    }
};


class LevelDirector{
    LevelBuilder * builder;

public:
    void setBuilder(LevelBuilder * builder){
        this->builder = builder;
    }

    void buildMarioLevel(){
        this->builder->setPlatform("zoo");
        this->builder->setCharacter("simba");
        this->builder->setEnemy("mofasa");
    }

    void buildMarioLevelWithoutEnemy(LevelBuilder * Builder){
        builder->setPlatform("zoo");
        builder->setCharacter("simba");
    }
};


int main() {
    MarioLevelBuilder * m = new MarioLevelBuilder();
    LevelDirector * l = new LevelDirector();
    l->setBuilder(m);
    l->buildMarioLevel();
    const Level * s = m->getLevel();
    cout << s->enemy << " " << s->platform << " " << s->character;


    return 0;
}
