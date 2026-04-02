#include <iostream>

int main()
{
    // decltype的含义
    std::cout << "decltype用于返回精准类型,不作任何退化" << std::endl;

    // 示例
    int a = 100;
    int* b = &a;
    int& c = a;

    decltype(a) a1;     // a1同a为int
    decltype(b) b1;     // b1同b为指针
    decltype(c) c1 = a;  // c1同c为引用

    std::cout << "\n==== decltype的三种用法 ====" << std::endl;

    std::cout << "\n1、变量名" << std::endl;

    // 同示例，也就是括号里为变量名
    std::cout << "\na1是不是int : " << std::is_same<decltype(a1),int>::value << std::endl;
    std::cout << "b1是不是指针 : " << std::is_same<decltype(b1),int*>::value << std::endl;
    std::cout << "c1是不是引用 : " << std::is_same<decltype(c1),int&>::value << std::endl;

    std::cout << "\n2、表达式" << std::endl;

    decltype(a + 1) a2;         // 算术运算的得到的都是右值，返回值类型int
    decltype(c + 1) c2;         // 引用进行运算得到右值，返回类型int
    decltype(b + 1) b2;         // 算术运算得到右值，返回类型int*

    std::cout << "\na2是不是int : " << std::is_same<decltype(a2),int>::value << std::endl;
    std::cout << "b2是不是指针 : " << std::is_same<decltype(b2),int*>::value << std::endl;
    std::cout << "c2是不是int : " << std::is_same<decltype(c2),int>::value << std::endl;


    std::cout << "\n3、带括号的变量名" << std::endl;
    // 其实带括号的变量名也就是把括号里的变量名当作表达式进行推算

    decltype((a)) a3 = a;       // 括号内是左值，返回引用类型
    decltype((c + 1)) c3;       // 括号内是右值，返回类型int
    decltype((b + 1)) b3;       // 括号内是右值，返回类型int*

    std::cout << "\na3是不是引用 : " << std::is_same<decltype(a3),int&>::value << std::endl;
    std::cout << "b3是不是指针 : " << std::is_same<decltype(b3),int*>::value << std::endl;
    std::cout << "c3是不是int : " << std::is_same<decltype(c3),int>::value << std::endl;

    std::cout << "\n==== decltype和const ====" << std::endl;

    const int i = 100;
    decltype(i) i1 = 10;

    // decltype会保留const
    std::cout << "\ni1是不是const int : " << std::is_const<decltype(i1)>::value << std::endl;

    decltype(i + 1) i2;
    // 顶层const进行四则运算后会删去顶层const
    std::cout << "\ni2是不是const int : " << std::is_const<decltype(i2)>::value << std::endl;

    // 底层const不会消失
    const int* p = &i;
    decltype(p + 1) p1 = &i;
    // *p1 = 1000;  无法通过指针修改值，说明依旧是底层const

    std::cout << "\np1是不是底层const : " 
              << std::is_const<std::remove_pointer<decltype(p1)>::type>::value 
              << std::endl;

    std::cout << "\n综上,decltype的推导规则有三 :"
              << "\n1、变量名推导为相同类型(该变量是什么类型就推导为什么类型)"
              << "\n2、对带括号的变量名当作表达式进行推导"
              << "\n3、对于表达式,先看表达式结果，如果是左值，就推导为引用，如果是右值，就返回相同类型"
              << "\n4、对于const,decltype不会忽视const,但是如果const进行了运算,顶层const消失,底层const保留"
              << std::endl;

    return 0;

}