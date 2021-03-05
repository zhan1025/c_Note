#	extern "C":实现C++和C的混合编程



```c++
//myfun.h
void display();
//myfun.c
#include <stdio.h>
#include "myfun.h"
void display(){
   printf("C++：test");
}
//main.cpp
#include <iostream>
#include "myfun.h"
using namespace std;
int main(){
   display();
   return 0;
}
```

在此项目中，主程序是用 C++ 编写的，而 display() 函数的定义是用 C 语言编写的。从表面上看，这个项目很完整，我们可以尝试运行它：

In function `main': undefined reference to `display()'

如上是调用 GCC 编译器运行此项目时给出的错误信息，指的是编译器无法找到 main.cpp 文件中 display() 函数的实现代码。导致此错误的原因，就是因为 C++ 和 C 编译程序的方式存在差异。
通过学习《》一节我们知道，之所以 C++ 支持函数的重载，是因为 C++ 会在程序的编译阶段对函数的函数名进行“再次重命名”，例如：显然通过重命名，可以有效避免编译器在程序链接阶段无法找到对应的函数。
`_Swap`

> 不同的编译器有不同的重命名方式，但根据 C++ 标准编译后的函数名几乎都由原有函数名和各个参数的数据类型构成，而根据 C 语言标准编译后的函数名则仅有原函数名构成。这里仅仅举例说明，实际情况可能并非如此。

这也就意味着，使用 C 和 C++ 进行混合编程时，考虑到对函数名的处理方式不同，势必会造成编译器在程序链接阶段无法找到函数具体的实现，导致链接失败。
幸运的是，C++ 给出了相应的解决方案，即借助 extern "C"，就可以轻松解决 C++ 和 C 在处理代码方式上的差异性。



##	extern  "C"

extern 是 C 和 C++ 的一个关键字，但对于 extern "C"，读者大可以将其看做一个整体，和 extern 毫无关系。
extern "C" 既可以修饰一句 C++ 代码，也可以修饰一段 C++ 代码，它的功能是让编译器以处理 C 语言代码的方式来处理修饰的 C++ 代码。

为了避免 display() 函数以不同的编译方式处理，我们应该使其在 main.cpp 文件中仍以 C 语言代码的方式处理，这样就可以解决函数名不一致的问题。因此，可以像如下这样来修改 myfun.h：

```c++
#ifdef __cplusplus
extern "C" void display();
#else
void display();
#endif
```



可以看到，当 myfun.h 被引入到 C++ 程序中时，会选择带有 extern "C" 修饰的 display() 函数；反之如果 myfun.h 被引入到 C 语言程序中，则会选择不带 extern "C" 修饰的 display() 函数。由此，无论 display() 函数位于 C++ 程序还是 C 语言程序，都保证了 display() 函数可以按照 C 语言的标准来处理。

```c++
C++：test
```

在实际开发中，对于解决 C++ 和 C 混合编程的问题，通常在头文件中使用如下格式：

```c++
#ifdef __cplusplus
extern "C" {
#endif

void display();

#ifdef __cplusplus
}
#endif
```



由此可以看出，extern "C" 大致有 2 种用法，当仅修饰一句 C++ 代码时，直接将其添加到该函数代码的开头即可；如果用于修饰一段 C++ 代码，只需为 extern "C" 添加一对大括号，并将要修饰的代码囊括到括号内即可。