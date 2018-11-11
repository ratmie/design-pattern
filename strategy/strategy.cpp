#include <iostream>
#include <cstdlib>
#include <functional>

class Duck {
    std::function<void(void)> quackBehavior;
public:
    void performQuack() {
        quackBehavior();
    };
    
    void setQuackBehavior(std::function<void(void)> f) {
		quackBehavior = f;
    };
};

void quack() {
	std::cout << "ガーガー" << std::endl;
}

void muteQuack() {
	std::cout << "<沈黙>" << std::endl;
}

class MallardDuck : public Duck {
public:
    MallardDuck() {
        setQuackBehavior(quack);
    }
};

int main()
{
    Duck *mallard = new MallardDuck();
	mallard->performQuack();
	mallard->setQuackBehavior(muteQuack);
	mallard->performQuack();
}