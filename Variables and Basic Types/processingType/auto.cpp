#include <iostream>
#include <type_traits>

int main ()
{
    // auto的含义
    std::cout << "auto也就是让编译器自己推导该变量的类型,简化书写\n" << std::endl;

    // 实践
    auto a = 3;         // 推导为i，也就是int
    auto b = 3.14;      // 推导为d，也就是double
    auto c = 3.14f;     // 推导为f，也就是float
    auto d = 'A';       // 推导为c，也就是char

    std::cout << "a的类型推导为 : " << typeid(a).name() << std::endl;
    std::cout << "b的类型推导为 : " << typeid(b).name() << std::endl;
    std::cout << "c的类型推导为 : " << typeid(c).name() << std::endl;
    std::cout << "d的类型推导为 : " << typeid(d).name() << std::endl;

    // 推导逻辑
    std::cout << "\n==== auto的类型推导逻辑 ====\n" << std::endl;

    auto n1 = 100;
    auto n2 = 3.14f;
    auto n3 = 3.14;
    auto n4 = 3.14L;
    auto n5 = 100l;
    auto n6 = 100ll;
    auto n7 = 'S';

    std::cout << "n1的类型为: " << typeid(n1).name() << std::endl;
    std::cout << "n2的类型为: " << typeid(n2).name() << std::endl;
    std::cout << "n3的类型为: " << typeid(n3).name() << std::endl;
    std::cout << "n4的类型为: " << typeid(n4).name() << std::endl;
    std::cout << "n5的类型为: " << typeid(n5).name() << std::endl;
    std::cout << "n6的类型为: " << typeid(n6).name() << std::endl;
    std::cout << "n7的类型为: " << typeid(n7).name() << std::endl;

    std::cout << "\n==== auto和指针、引用 ====\n" << std::endl;

    // auto在推导过程中会忽略&和顶层const,但无法忽略底层const和指针

    int a1 = 100;
    int& r = a1;
    int* p = &a1;
    const int& cr = a1;         // 虽然说是底层const,但实际上不做区分
    const int* cp = &a1;        // 底层const

    // 非const
    auto r1 = r;    // 推导为int，删去了引用符号，也就是说r1不是引用
    auto p1 = p;    // 推导为int*

    std::cout << "r1是引用? " << std::is_reference<decltype(r1)>::value << std::endl;
    std::cout << "p1的类型为 : " << typeid(p1).name() << std::endl;

    std::cout << "\n引用在auto的推导过程中会被忽视,因为引用其实显示的还是指向的对象的相关信息"
              << "\n如果想要保留引用的话,需要加上&"
              << std::endl;

    auto& rx = r;       // 这样才会保留引用

    std::cout << "\nrx是引用? " << std::is_reference<decltype(rx)>::value << std::endl;

    // const
    auto r2 = cr;   // 推导为int，被当作顶层const而删去const了
    auto p2 = cp;   // 推导为const int*，底层const不能删除

    std::cout << "\nr2是引用? " << std::is_reference<decltype(r2)>::value << std::endl;
    std::cout << "r2 是 const? " << std::is_const<std::remove_reference<decltype(r2)>::type>::value << std::endl; 
    std::cout << "p2的类型为 : " << typeid(p2).name() << std::endl;

    std::cout << "\n因为常量引用本身的const在实际中不做区分,所以在推断中会当作顶层const直接删去"
              << "\n要想保留,依旧得额外添加const"
              << std::endl;
    
    const auto& rx2 = cr;

    // typeid在推导过程中也会忽略引用和顶层const，所以需要更换方式
    std::cout << "\nrx2是引用? " << std::is_reference<decltype(rx2)>::value << std::endl;
    std::cout << "rx2 是 const? " << std::is_const<std::remove_reference<decltype(rx2)>::type>::value << std::endl;
    
    std::cout << "\n==== auto 推导规则总结 ====" << std::endl;
    std::cout << "auto 会:" << std::endl;
    std::cout << "  - 去掉引用 (&)" << std::endl;
    std::cout << "  - 去掉顶层 const" << std::endl;
    std::cout << "  - 保留底层 const (指针)" << std::endl;
    std::cout << "  - 保留指针 (*)" << std::endl;
    std::cout << "\n要保留引用: 用 auto&" << std::endl;
    std::cout << "要保留 const: 用 const auto" << std::endl;

    return 0;

}