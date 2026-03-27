#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "\niomanip头文件主要用于各种格式化输出\n" << std::endl;

    std::cout << "\n==== 精度控制 ====" << std::endl;
    double d1 = 3.1415926535;
    double d2 = 314159.2653571243137213;
    std::cout << "默认输出(6位有效) : "
              << "\nd1 = " << d1 << std::endl; 
    
    std::cout << "\n控制有效数字位数输出 : " << std::endl;
    std::cout << std::setprecision(2) << d1 << std::endl;
    std::cout << std::setprecision(4) << d1 << std::endl;
    std::cout << std::setprecision(8) << d1 << std::endl;

    std::cout << "\n控制小数位数输出(fixed模式) : " << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(2) << d1 << std::endl;
    std::cout << std::setprecision(4) << d1 << std::endl;
    std::cout << std::setprecision(8) << d1 << std::endl;

    std::cout << "\n科学计数法输出()"
    std::cout << std::scientific;
    std::cout << std::setprecision(2) << d1 << std::endl;
    std::cout << std::setprecision(4) << d1 << std::endl;
    std::cout << std::setprecision(8) << d1 << std::endl;
    std::cout << std::setprecision(9) << d2 << std::endl; 
}