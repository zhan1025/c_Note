#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> names; // 创建一个空的 vector
    std::vector<int> vec2(5, 10); // 创建一个包含 5 个元素的 vector，每个元素的值为 10
    std::vector<int> vec3(vec2.begin(), vec2.end()); // 使用 vec2 的元素创建一个 vector

  names.push_back("Alice"); // 在 vector 的末尾添加一个元素
  names.push_back("Bob"); // 在 vector 的末尾添加一个元素

  // for(int i=0; i < names.size(); i++) {
  //   std::cout << names[i] << "\n"<<std::endl;
  // }
  std::vector<std::string>::iterator it = names.begin();// 获取 vector 的迭代器
  while(it != names.end()) {
    std::cout << *it << "\n"<<std::endl;
    ++it;
  }
    return 0;
}