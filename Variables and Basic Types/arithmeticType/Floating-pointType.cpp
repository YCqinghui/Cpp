#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
    std::cout << "==== 浮点型相关 ====" << std::endl;

    std::cout << "浮点型大小 : " << std::endl;
    std::cout << "float的大小为 : " << sizeof(float) << " 字节" << std::endl;
    std::cout << "double的大小为 : " << sizeof(double) << " 字节" << std::endl;
    std::cout << "long double的大小为 : " << sizeof(long double) << " 字节" << std::endl;

    std::cout << "浮点型类型编码" << std::endl;
    std::cout << "float的类型编码为 : " << typeid(float).name() << std::endl;
    std::cout << "double的类型编码为 : " << typeid(double).name() << std::endl;
    std::cout << "long double的类型编码为 : " << typeid(long double).name() << std::endl;

    std::cout << "浮点型字面量 : " << std::endl;
    auto s1 = 3.14f;
    auto s2 = 3.14;
    auto s3 = 3.14L;
    std::cout << "变量s1的类型为 : " << typeid(s1).name() << "(后缀f表示类型为float)" << std::endl;
    std::cout << "变量s2的类型为 : " << typeid(s2).name() << "(无后缀的浮点型默认为double)" << std::endl;
    std::cout << "变量s3的类型为 : " << typeid(s3).name() << "(后缀为L的表示类型为long double)" << std::endl;

    std::cout << "各浮点型精度(小数) : " << std::endl;
    std::cout << "float : " << std::numeric_limits<float>::digits10 << "位" << std::endl;
    std::cout << "double : " << std::numeric_limits<double>::digits10 << "位" << std::endl;
    std::cout << "long double : " << std::numeric_limits<long double>::digits10 << "位" << std::endl;

    std::cout << "实例(以1/3为例) : " << std::endl;
    float f1 = 1/3.0f;
    double d1 = 1/3.0;
    long double ld1 = 1/3.0L;
    std::cout << std::fixed;
    std::cout << "20位小数下的float输出 : " << std::setprecision(20) << f1 
              << "(很明显,在第七位小数后就开始失去准确性)" << std::endl;
    std::cout << "20位小数下的double输出 : " << std::setprecision(20) << d1 
              << "(很明显,在第16位小数之后就开始失去准确性)" << std::endl; 
    std::cout << "20位小数下的long double输出 : " << std::setprecision(20) << ld1 
              << "(很明显,在第16位小数之后就开始失去准确性)" << std::endl; 
    std::cout << std::defaultfloat << std::setprecision(6) << std::endl;    // 恢复精度
              
    std::cout << "可以发现，实际精确度要比标定的精确度要多一位，这并不是标定的精确度有问题。\n"
              << "实际上，标定的精确度是最少能保证给出的准确的小数为，下一位或两位可能准确，但不能保证。\n"
              << "此外,在大多数平台中,long double和double并无不同,在少数平台,且17位小数往上,才能体现long double的作用。"
              << std::endl;

    std::cout << "小数计算 : " << std::endl;
    int i1 = 3;
    int i2 = 2;
    double d2 = 3;
    double d3 = 2;
    std::cout << "整型相除的结果 : " << i1 / i2 << " (删去小数位,只留整数位,且并非四舍五入)" << std::endl;
    std::cout << "浮点型相除的结果 : " << d2 / d3 << " (保留小数位)" << std::endl;
    std::cout << "混合相除 : " << i1 / d3 << " (保留小数位)" << std::endl;
    
    std::cout << "可以看出，只有当计算中存在浮点数的时候，结果才能够有小数，否则删去小数位。" << std::endl;
    
    std::cout << "科学计数法 : " << std::endl;
    std::cout << "1.5e4 = " << 1.5e4 << "(1.5*10^4)" << std::endl;
    std::cout << "1.5e-4 = " << 1.5e-4 << "(1.5*10^-4)" << std::endl;

    std::cout << "=== 浮点数误差 ===" << std::endl;
    std::cout << "存储误差 : " << std::endl;
    std::cout << "1.5e-10 = " << std::fixed << std::setprecision(30) << 1.5e-10
              << " (原本小数那边应该是0.~15~的,但是在高精度下变成了0.~14999~,这个就是存储误差，难以避免的)" 
              << std::defaultfloat << std::setprecision(2) << std::endl;
    std::cout << " 0.1+0.2 是否等于 0.3 " << std::endl;
    double d4 = 0.1 + 0.2;
    double d5 = 0.3;
    std::cout << "0.1 + 0.2 = " << d4 << std::endl;
    std::cout << "0.3 = " << d5 << std::endl;
    if (d4 == d5)
    {
        std::cout << "没有误差，双方相等" << std::endl;
    }
    else
    {
        std::cout << "存在误差，双方不等" << std::endl;
    }

    std::cout << "累加误差之10个0.1相加是否等于1 : " << std::endl;
    double sum = 0.1;
    for (int i = 1 ; i < 10 ; i++)
    {
        sum += 0.1;
    }
    if (sum == 1.0)
    {
        std::cout << "sum = " << sum << "\n"
                  << "没有误差，二者相等" << std::endl;
    }
    else
    {
        std::cout << "sum = " << sum << "\n"
                  << "有误差，二者不等" << std::endl;
    }

    std::cout << "正确的浮点数比较方式 : " << std::endl;
    if ((d5 - d4) < 1e-10)
    {
        std::cout << "二者相等" << std::endl;
    }

    std::cout << "综上所述，浮点数普遍存在误差"
              << "所以很多时候浮点数的比较通常不是直接比较，而是用一种约等于的方式进行比较" << std::endl;
    
    std::cout << std::endl;
    std::cout << "浮点数的特殊值 : " << std::endl;
    // 1、无穷大
    double inf1 = INFINITY;
    double inf2 = 1.0 / 0.0;

    // 2、负无穷大
    double neg_inf = -1.0 / 0.0;

    // 3、NAN(不是数，not a number)
    double nan1 = NAN;
    double nan2 = 0.0 / 0.0;

    std::cout << "无穷大为 : " << inf1 << "\n"
              << "无穷大为 : " << inf2 << "\n"
              << "负无穷大为 : " << neg_inf << "\n"
              << "NAN为 : " << nan1 << "\n"
              << "NAN为 : " << nan2 << std::endl;
    
    std::cout << "判断特殊值 : " << std::endl;
    std::cout << isinf(inf1) << std::endl;
    std::cout << isinf(nan1) << std::endl;
    std::cout << isinf(3.14) << std::endl;
    std::cout << "输出1表示真,说明是特殊值,输出0为假,说明不是特殊值" << std::endl;

    std::cout << "float极限值 : " << std::endl;
    std::cout << "最大值为 : " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "最小正数为 : " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "最小值为 : " << std::numeric_limits<float>::lowest() << std::endl;

    std::cout << "double极限值 : " << std::endl;
    std::cout << "最大值为 : " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "最小值为 : " << std::numeric_limits<double>::min() << std::endl;
    
    return 0;

}