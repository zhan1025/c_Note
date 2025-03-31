#include <iostream>
#include <string>


class Lovers {
  public:
    Lovers(std::string theName);
    void kiss(Lovers *lover);
    void ask(Lovers *lover, std::string something);
  protected:
    std::string name;
    
    friend class Others; // 好友类
};

class Others {
  public:
    Others(std::string theName);
    void kiss(Lovers *lover);
  protected:
    std::string name;
};
class Boyfriend : public Lovers {
  public:
    Boyfriend(std::string theName);
};

class Girlfriend : public Lovers {
  public: 
    Girlfriend(std::string theName);
};


Lovers::Lovers(std::string theName) {
  name = theName;
}
void Lovers::kiss(Lovers *lover) {
  std::cout << name << " kiss " << lover->name << std::endl;
}
void Lovers::ask(Lovers *lover, std::string something) {
  std::cout << name << " ask " << lover->name << "help me" << something << std::endl;
}

//
Boyfriend::Boyfriend(std::string theName) : Lovers(theName) {}
Girlfriend::Girlfriend(std::string theName) : Lovers(theName) {}

Others::Others(std::string theName) {
  name = theName;
}
void Others::kiss(Lovers *lover) {
  std::cout << name << " kiss kiss" << lover->name << std::endl;
}
int main() {
  Boyfriend boyfriend("A Boy");
  Girlfriend girlfriend("B Girl");
  Others others("C Others");

  girlfriend.kiss(&boyfriend);
  girlfriend.ask(&boyfriend, "to buy me a flower");

  std::cout << "-----------------" << std::endl;
  others.kiss(&girlfriend);
  return 0;
}