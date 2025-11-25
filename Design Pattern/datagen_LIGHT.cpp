#include <iostream>

class AvatarState {
    public :
        virtual void action() = 0;
        virtual void next();
};

class Glad : AvatarState {
    public :
        void action() override { std::cout << "Glad\n"; }
};

class Happy : AvatarState {
    public :
        void action() override { std::cout << "Happy\n"; }
};

class Sad : AvatarState {
    public :
        void action() override { std::cout << "Sad\n"; }
};

class Angry : AvatarState {
    public :
        void action() override { std::cout << "Angry\n"; }
};
class Grumpy : AvatarState {
    public :
        void action() override { std::cout << "Grumpy\n"; }
};

int main() {

    

    return 0;
}