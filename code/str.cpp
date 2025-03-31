#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "输入一个字符串:";
    std::cin >> str;
    std::cout << str; // 输出字符串
    std::cin.ignore(); // 忽略缓冲区中的换行符
    std::cout << "输入";
    std::cin.get(); // 等待用户按下回车键

    return 0;
}