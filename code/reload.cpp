#include <iostream>

using namespace std;

void calc(int arg);
void calc(int arg, int arg2);
void calc(int arg, int arg2, int arg3);

int main() {
  calc(2);
  calc(3,4);
  calc(1,2,3);
  return 0;
}

void calc(int arg) {
    cout << arg*arg << "\n" << endl;
}
void calc(int arg, int arg2) {
    cout << arg*arg2 << "\n" << endl;
}
void calc(int arg, int arg2, int arg3) {
    cout << arg + arg2 + arg3 << "\n" << endl;
}