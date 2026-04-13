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

    std::cout << "\n科学计数法输出(scientific模式) : " << std::endl;
    std::cout << std::scientific;
    std::cout << std::setprecision(2) << d1 << std::endl;
    std::cout << std::setprecision(4) << d1 << std::endl;
    std::cout << std::setprecision(8) << d1 << std::endl;
    std::cout << std::setprecision(9) << d2 << std::endl; 

    // 其实科学计数法的输出模式的setprecision主要控制的是将数字转换为科学计数法后保留的小数位数
    // 若无法完全输出所有小数，则采用四舍五入

    // 恢复默认输出模式，也就是输出六位有效数字
    std::cout << std::defaultfloat << std::setprecision(6) << std::endl;

    std::cout << "==== 宽度和对齐 ====" << std::endl;

    // setw可以设置输出宽度（仅生效一个输出）
    std::cout << "\n默认右对齐 : " << std::endl;
    std::cout << std::setw(10) << -53 << std::endl; //  设置为下一个输出单独占据10的长度
    std::cout << std::setw(10) << -3749 << std::endl;
    std::cout << std::setw(10) << -123456 << std::endl;

    std::cout << "\n设置右对齐 : " << std::endl;
    std::cout << std::right;
    std::cout << std::setw(10) << -53 << std::endl;
    std::cout << std::setw(10) << -3749 << std::endl;
    std::cout << std::setw(10) << -123456 << std::endl;

    std::cout << "\n设置左对齐 : " << std::endl;
    std::cout << std::left;
    std::cout << std::setw(10) << -53 << std::endl;
    std::cout << std::setw(10) << -3749 << std::endl;
    std::cout << std::setw(10) << -123456 << std::endl;

    // 内部对齐指符号左对齐，数字右对齐
    std::cout << "\n设置内部对齐 : " << std::endl;
    std::cout << std::internal;
    std::cout << std::setw(10) << -53 << std::endl;
    std::cout << std::setw(10) << -3749<< std::endl;
    std::cout << std::setw(10) << -123456 << std::endl;

    std::cout << "\n多单位无效格式 : " << std::endl;
    std::cout << std::internal;
    std::cout << std::setw(10) << 52 << "+"
              << "\n加号并不会按照内部对齐的格式输出,"
              << "因为setw的格式输出只作用于后一个输出\n" << std::endl;

    // 恢复默认对齐模式
    std::cout << std::right
              << "恢复对齐模式为默认的右对齐（对齐模式一旦设置若不改变，后续都不会变）" 
              << std::endl;
              
    std::cout << "\n==== 填充字符 ====" << std::endl;

    // setw设置宽度时空余的部分是默认使用空格填充，而我们可以手动设置这个填充

    std::cout << "\n用字符'*'填充 : " << std::endl;
    std::cout << std::setfill('*');
    std::cout << std::setw(10) << 52 << std::endl;
    std::cout << std::setw(10) << 1234 << std::endl;
    std::cout << std::setw(10) << 123456 << std::endl;

    std::cout << "\n用字符'0'填充 : " << std::endl;
    std::cout << std::setfill('0');
    std::cout << std::setw(10) << 12 << std::endl;
    std::cout << std::setw(10) << 1234 << std::endl;
    std::cout << std::setw(10) << 123456 << std::endl;

    // 恢复默认填充
    std::cout << std::setfill(' ')
              << "填充模式一样，都是一经设置，若未改变，后续都为此模式"
              << std::endl;

    std::cout << "\n==== 进制控制 ====" << std::endl;

    int num = 255;

    std::cout << "\n切换输出进制 : " << std::endl;
    std::cout << "十进制输出 : " << std::dec << num << std::endl;
    std::cout << "十六进制输出 : " << std::hex << num << std::endl;
    std::cout << "八进制输出 : " << std::oct << num << std::endl;

    std::cout << "\n显示进制前缀的输出 : " << std::endl;
    std::cout << std::showbase;
    std::cout << "显示前缀的十进制输出 : " << std::dec << num << std::endl;
    std::cout << "显示前缀的十六进制输出 : " << std::hex << num << std::endl;
    std::cout << "显示前缀的八进制输出 : " << std::oct << num << std::endl;
    std::cout << std::noshowbase;   // 关闭前缀输出，随用随关，养成好习惯

    std::cout << "\n大写十六进制的输出 : " << std::endl;
    std::cout << std::uppercase;
    std::cout << "大写的十六进制输出 : " << std::hex << num << std::endl;
    std::cout << std::nouppercase;  // 随用随关

    // 进制设置也是影响以下所有，所以更改完进制可以讲进制重新改为十进制
    std::cout << std::dec;

    std::cout << "\n==== 格式化布尔输出 ====\n" << std::endl;
    
    bool t = true;
    bool f = false;

    // 默认情况下，布尔类型如果正确则输出数字1，错误则输出数字0
    std::cout << "默认输出 : " 
              << t << "    " << f << std::endl;

    // 如果需要的话，可以设置格式，改为输出true和false
    std::cout << std::boolalpha;
    std::cout << "英文输出 : "
              << t << "    " << f << std::endl;
    std::cout << std::noboolalpha;  // 随用随关

    return 0;

}