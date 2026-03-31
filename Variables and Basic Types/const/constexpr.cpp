#include <iostream>

int main()
{
    // 常量表达式的含义
    std::cout << "常量表达式就是编译期就能计算出结果的表达式" << std::endl;

    // 常量表达式类型
    std::cout << "\n==== 常量表达式类型 ====\n" << std::endl;

    std::cout << "1、字面量及其运算" << std::endl;

    10;
    3 * 4;
    3 + 4;

    std::cout << "\n2、以字面量及其运算初始化的变量" << std::endl;

    int a = 10;
    int b = 3 * 4;
    int c = 3 + 4;

    std::cout << "\n3、字面量与以字面量及其运算初始化的变量的混和表达式,以及以这个表达式初始化的变量" << std::endl;

    a + 10;
    a * 4;
    int d = a + 10;
    int f = a * 4;



}