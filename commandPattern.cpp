// command pattern
#include <iostream>

using namespace std;
// the light is the reciever
class Light{
public:
    void lightOn(){
        cout << "the light is on\n";
    }
    void lightOff(){
        cout << "the light is off\n";
    }
};

// command
class Command{
public:
    virtual void execute() = 0;
};

//concrete command 1
class turnOnCommand: public Command{
    Light * light;
public:
    turnOnCommand(Light * light1){
        this->light = light1;
    }
    void execute() override{
        this->light->lightOn();
    }
};

// concrete command 2
class turnOffCommand: public Command{
    Light * light;
public:
    turnOffCommand(Light * light1){
        this->light = light1;
    }
    void execute() override{
        this->light->lightOff();
    }
};

// invoker
class HandleLight{
    Command * command;
public:
    HandleLight() = default;

    void setCommand(Command * command){
        this->command = command;
    }

    void BottomPressed(){
        command->execute();
    }
};




int main() {
    Light * l1 = new Light;
    Command * c1 = new turnOnCommand(l1);
    Command * c2 = new turnOffCommand(l1);
    HandleLight * h = new HandleLight();
    h->setCommand(c1);
    h->BottomPressed();
    h->setCommand(c2);
    h->BottomPressed();
}
