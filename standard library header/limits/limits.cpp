#include <iostream>
#include <limits>
#include <cmath>

int main()
{
    std::cout << "limits用于查询极限值" << std::endl;

    std::cout << "==== 整型极限值 ====" << std::endl;
    std::cout << "int : " << std::endl;
    std::cout << "int最大值 : " << std::numeric_limits<int>::max() << std::endl; 
    std::cout << "int最小值 : " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "int最小值 : " << std::numeric_limits<int>::lowest() << std::endl;

    // 在整型中lowest和min效果一样

    std::cout << "\nunsigned int : " << std::endl;
    std::cout << "unsigned int最大值 : " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "unsigned int最小值 : " << std::numeric_limits<unsigned int>::min() << std::endl;

    std::cout << "\nlong long : " << std::endl;
    std::cout << "long long最大值 : " << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "long long最小值 : " << std::numeric_limits<long long>::min() << std::endl;

    std::cout << "\n==== 浮点数极限值 ====" << std::endl;
    std::cout << "float : " << std::endl;
    std::cout << "最大值 : " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "最小正数值 : " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "最小值 : " << std::numeric_limits<float>::lowest() << std::endl;

    std::cout << "\ndouble : " << std::endl;
    std::cout << "最大值 : " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "最小正数值 : " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "最小值 : " << std::numeric_limits<double>::lowest() << std::endl;

    // 在浮点数中，min表示的是最小正数，lowest才是真正最小的值

    std::cout << "\n==== 精度 ====" << std::endl;
    std::cout << "二进制精度 : " << std::endl;
    std::cout << "int的二进制位数 : " << std::numeric_limits<int>::digits << "位" 
              << "\n意味着int能表示2^" << std::numeric_limits<int>::digits << "以内的数" << std::endl;
    std::cout << "float的尾数位数 : " << std::numeric_limits<float>::digits << "位"
              << "\n意味着float能表示2^" << std::numeric_limits<float>::digits << "以内的数" << std::endl;
    std::cout << "double的尾数位数 : " << std::numeric_limits<double>::digits << "位"
              << "\n意味着double能表示2^" << std::numeric_limits<double>::digits << "以内的数" << std::endl;

    std::cout << "\n十进制精度(确保精确位数) : " << std::endl;
    std::cout << "float : " << std::numeric_limits<float>::digits10 << "位" << std::endl;
    std::cout << "double : " << std::numeric_limits<double>::digits10 << "位" << std::endl;

    std::cout << "\n十进制极限精度(后两位不确定精确) : " << std::endl;
    std::cout << "float : " << std::numeric_limits<float>::max_digits10 << "位" << std::endl;
    std::cout << "double : " << std::numeric_limits<double>::max_digits10 << "位" << std::endl;

    std::cout << "\n==== epsilon(机器精度) ====" << std::endl;
    std::cout << "float epsilon : " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "double epsilon : " << std::numeric_limits<double>::epsilon() << std::endl;

    // 机器精度就是计算机最小能辨别的容差，也就是两个数差值小于一个epsilon的话就判相等，大于则不等

    double d1 = 1.0;
    double d2 = 1.0 + 0.5 * std::numeric_limits<double>::epsilon();
    double d3 = 1.0 + 2 * std::numeric_limits<double>::epsilon();
    double d4 = 0.3;
    double d5 = 0.1 + 0.2;
    if (d1 == d2)
    {
        std::cout << "差值小于一个epsilon,d1与d2相等" << std::endl;
    }
    if (d3 != d1)
    {
        std::cout << "差值大于一个epsilon,d1与d3不等" << std::endl;
    }
    
    std::cout << "由于浮点数的误差,在计算机眼中,d4和d5并不相等,"
              << "如果我们想要令其被判定为相等,就需要借助epsilon了" << std::endl;
    if (std::abs(d4 - d5) < std::numeric_limits<double>::epsilon())
    {
        std::cout << "差值小于epsilon,二者相等" << std::endl;
    }

    // std::abs是隶属于头文件<cmath>的一个绝对值相关

    std::cout << "\n==== 特性 ====" << std::endl;
    std::cout << "int是否为整型 : "
              << std::numeric_limits<int>::is_integer << std::endl;
    std::cout << "int是否精确 : "
              << std::numeric_limits<int>::is_exact << std::endl;
    std::cout << "int是否有无穷大 : " 
              << std::numeric_limits<int>::has_infinity << std::endl;
    std::cout << "int是否有NAN : " 
              << std::numeric_limits<int>::has_quiet_NaN << std::endl;

    std::cout << "\n==== 特殊值 ====" << std::endl;
    std::cout << "float的无穷大 : " << std::numeric_limits<float>::infinity() << std::endl;
    std::cout << "doubel的无穷大 : " << std::numeric_limits<double>::infinity() << std::endl;
    std::cout << "float的NaN : " << std::numeric_limits<float>::quiet_NaN() << std::endl;

    return 0;

}