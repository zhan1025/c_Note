#include <iostream>
#include <string>

class Animal 
{
public:
    std::string mouth;

    void eat();
    void sleep();
    void drool();
};

class Pig : public Animal 
{
public:
    void climb();
};

class Turtle : public Animal 
{
public:
    void swim();
};

void Animal::eat()
{
    std::cout << "I'm eating!" << std::endl;
}

void Animal::sleep()
{
    std::cout << "I'm sleeping! Don't ditrub me!" << std::endl;
}

void Animal::drool()
{
    std::cout << "drool" << std::endl;
}

void Pig::climb()
{
    std::cout << "climb" << std::endl;
}

void Turtle::swim()
{
    std::cout << "swim" << std::endl;
}

int main ()
{
    Pig pig;
    Turtle turtle;

    pig.eat();
    turtle.eat();
    pig.climb();
    turtle.swim();
    return 0;
}