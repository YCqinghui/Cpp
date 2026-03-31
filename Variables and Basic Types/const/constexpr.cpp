#include <iostream>

int i = 100;
int global = 100;


int main()
{
    // 常量表达式的含义
    std::cout << "常量表达式就是编译期就能计算出结果的表达式" << std::endl;

    // 常量表达式类型
    std::cout << "\n==== 常量表达式类型 ====\n" << std::endl;

    std::cout << "1、字面量及其运算" << std::endl;

    // 10
    // 3 * 4
    // 3 + 4

    std::cout << "\n2、以字面量及其运算初始化的常量" << std::endl;

    const int a = 10;
    const int b = 3 * 4;
    const int c = 3 + 4;

    std::cout << "\n3、字面量与以字面量及其运算初始化的常量的混和表达式,以及以这个表达式初始化的常量" << std::endl;

    // a + 10
    // a * 4
    const int d = a + 10;
    const int f = a * 4;

    std::cout << "\n对于const来说,并非所有的const变量都是常量表达式"
              << "\n只有满足以上条件的const变量才是常量表达式"
              << std::endl;

    std::cout << "\n==== constexpr相关 ====" << std::endl;

    std::cout << "\nconstexpr就等于是个标记,就是告诉程序，这个变量是常量表达式"
              << "\n因此,constexpr定义的变量必须是常量表达式"
              << std::endl;
    
    constexpr int ce1 = 100;
    constexpr int ce2 = a * 3;
    constexpr int ce3 = 3 * 4;
    // 像在这种语句中，，constexpr覆盖了整个语句，所以常量本身和其初始化的值都必须是常量表达式，有一个不是都不行

    std::cout << "\n其实也就是相当于将const定义的常量表达式中的const改成了constexpr"
              << "\n其效果就在于让程序一眼识别这是常量表达式"
              << std::endl;

    std::cout << "\n==== constexpr和指针 ====" << std::endl;

    const int* p = &i;      // 底层const
    constexpr int* p1 = &i;     // 顶层const，constexpr只作用于指针本身，只要指针是常量表达式就行
                                // 但要想指针是常量表达式，就必须指向函数体外的变量

    std::cout << "\n首先,这两个指针就不同"
              << "\n以const作为修饰的指针是底层const,而以constexpr作为修饰的指针是顶层const"
              << "\n其次,constexpr修饰的常量指针指向的对象必须在整个函数体之外"
              << "\n因为constexpr的作用效果仅针对指针,所以这个指针必须是常量表达式"
              << "\n但是在函数体内的变量的地址是不固定的,所以指向函数体内的指针不是常量表达式"
              << "\n所以只能指向函数体外的变量"
              << std::endl;

    std::cout << "\n==== constexpr 指针 vs const 指针 ====" << std::endl;

    int local = 200;

    // const 指针（底层 const）
    const int* p2 = &local;      // ✅ 可以指向局部变量
    const int* p3 = &global;     // ✅ 可以指向全局变量

    // constexpr 指针（顶层 const）
    constexpr int* p4 = &global;     // ✅ 只能指向全局/静态
    // constexpr int* p4 = &local;   // ❌ 不能指向局部

    std::cout << "\nconst 指针：底层 const,可以指向任何变量" << std::endl;
    std::cout << "constexpr 指针：顶层 const,必须指向全局/静态变量" << std::endl;

    return 0;

}