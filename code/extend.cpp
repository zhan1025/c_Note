#include <iostream>
#include <string>


 class Animal{
    public:
      Animal(std::string theName);
      std::string name;
 };

 class Pig : public Animal{
    public:
      Pig(std::string theName);
 };


 Animal::Animal(std::string theName){
    name = theName;
 }

 Pig::Pig(std::string theName) : Animal(theName){
   
 }
 
int main(){


  return 0;
}