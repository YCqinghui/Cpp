#include <iostream>

int main()
{
    // 类型别名的含义
    std::cout << "类型别名,顾名思义,就是给类型名称取一个别的名字,类似引用" << std::endl;

    // 如何定义类型别名
    std::cout << "\n==== 定义类型别名的两种方式 ====" << std::endl;

    std::cout << "\n1、typedef" << std::endl;

    typedef int len;
    typedef double def;

    len a = 3;  // 等价于 int a = 3
    def d = 4;  // 等价于 double d = 4;

    std::cout << "a的类型为:" << typeid(a).name() << std::endl;
    std::cout << "d1的类型为:" << typeid(d).name() << std::endl;


    std::cout << "\n2、using" << std::endl;

    using leng = int;
    using deft = double;

    leng a1 = 3;    // 等价于 int a1 = 3
    deft d1 = 4;    // 等价于double d1 = 4;
    std::cout << "a1的类型为:" << typeid(a1).name() << std::endl;
    std::cout << "d1的类型为:" << typeid(d1).name() << std::endl;


    std::cout << "\n==== 类型别名和复合类型 ====\n" << std::endl;

    // 用类型别名替代复合类型，会有意料之外的效果
    using prt = int*;       // 这里的prt实际上是将int和*一起替换了
    prt p = &a;            // 不用加*，因为已经包含了

    std::cout << "p1的类型为:" << typeid(p).name() << std::endl;

    // 引用也是一样
    using ref = int&;
    ref r1 = a;

    std::cout << "r1的类型为:" << typeid(r1).name() << std::endl;

    std::cout << "\n类型别名与复合类型的陷阱 : " << std::endl;

    using pint = int*;
    pint p1, p2;    // p1 和 p2 都是 int* ✅

    // 如果不用别名
    int *p3, p4;    // p3 是 int*，p4 是 int ❌

    std::cout << "p1类型: " << typeid(p1).name() << std::endl;
    std::cout << "p2类型: " << typeid(p2).name() << std::endl;

    std::cout << "\n类型别名这种主要还是应对一些特别复杂的类型名,用于简化,也便于理解"
              << "\n所以类型别名一般都有自己的实际意义,就像变量名一样"
              << std::endl;

    return 0;

}