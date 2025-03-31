#include <iostream>

int main () {
  // 华氏度 == 摄氏度 * 9 / 5 + 32
  const unsigned short ADD_SUBTRACT = 32;
  const double RATIO = 9.0 / 5.0;

  double tempIn,tempOut;
  char typeIn,typeOut;

  std::cout << "请输入温度用 【xx.x C】或者 【xx.x F】格式输入: \n";
  std::cin >> tempIn >> typeIn;// 32.4 c
  std::cout << 12222 ;
  std::cin.ignore(100, '\n'); //忽略回车
  std::cout << "\n";
      
  switch(typeIn) {
    case 'c':
    case 'C':
      tempOut = tempIn * RATIO + ADD_SUBTRACT;
      std::cout << tempIn << " C = " << tempOut << " F" ;
      break;
    case 'f':
    case 'F':
      tempOut = (tempIn - ADD_SUBTRACT) / RATIO;
      std::cout << tempIn << " F = " << tempOut << " C" ;
      break;
    default:
      std::cout << "输入格式错误\n";
  }

  std::cout << "请按任意键退出\n" ;
  std::cin.get();
  return 0;
}