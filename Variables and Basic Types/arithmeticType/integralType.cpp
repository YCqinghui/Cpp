#include <iostream>
#include <bitset>
#include <cstdint>
#include <climits>

int main()
{
    // integral type    

    std::cout << "==== 整形大小（字节） ====" << std::endl;
    std::cout << "short     =   " << sizeof(short) << "字节" << std::endl;
    std::cout << "int       =   " << sizeof(int)   << "字节" << std::endl;
    std::cout << "long      =   " << sizeof(long)  << "字节" << std::endl;
    std::cout << "long long =   " << sizeof(long long) << "字节" << std::endl;

    std::cout << "==== 取值范围 ====" << std::endl;
    std::cout << "short     :   " << SHRT_MIN << "到" << SHRT_MAX << std::endl;
    std::cout << "int       :   " << INT_MIN << "到" << INT_MAX << std::endl;
    std::cout << "long      :   " << LONG_MIN << "到" << LONG_MAX << std::endl;
    std::cout << "long long :   " << LLONG_MIN << "到" << LLONG_MAX << std::endl;

    std::cout << "==== 无符号范围 ====" << std::endl;
    std::cout << "unsigned short    : 0 到  " << USHRT_MAX << std::endl;
    std::cout << "unsigned int      : 0 到  " << UINT_MAX  << std::endl;
    std::cout << "unsigned long     : 0 到  " << ULONG_MAX << std::endl;
    std::cout << "unsigned long long: 0 到  " << ULLONG_MAX << std::endl;

    std::cout << "=== 整形的进制转换 ===" << std::endl;
    int dec = 42;   // 十进制
    int oct = 052;  // 八进制，以0开头
    int hex = 0x2a; // 十六进制，以0x或0X开头
    int bin = 0b101010; // 二进制，以0b或0B开头
    std::cout << "常态自动转换为十进制:"   << std::endl;
    std::cout << "十进制 42         : " << dec << std::endl;
    std::cout << "八进制 052        : " << oct << std::endl;
    std::cout << "十六进制 0x2a     : " << hex << std::endl;
    std::cout << "二进制 0b101010   : " << bin << std::endl;

    std::cout << "=== 无前缀进制转换 ===" << std::endl;
    std::cout << "转八进制:\n"
              << std::oct << dec << std::endl;  // 前面的otc是八进制格式控制符，后面的dec是变量名
    std::cout << "转十六进制:\n"
              << std::hex << dec << std::endl;  // 前面的hex是十六进制格式控制符，后面的dec是变量名
    std::cout << "转十进制:\n"
              << std::dec << oct << std::endl;  // 前面的dec是十进制格式控制符，后面的oct是变量名
    std::cout << "(需要外加头文件)转二进制:\n"
              << std::bitset<8>(hex) << std::endl;  // 8是八位二进制，hex是要转换为二进制的变量

    /*
        注：默认状态下，输出模式是十进制模式，但使用了别的进制模式
            如：hex(十六进制)，oct(八进制)
            之后如果没有切换的话，就会一直保持该进制模式
    */

    std::cout << "=== 显示前缀的进制转换 ===" << std::endl;
    std::cout << "转八进制(含前缀):\n"
              << std::showbase << std::oct << dec << std::endl;
    std::cout << "转十六进制(含前缀):\n"
              << std::showbase << std::hex << dec << std::endl;
    std::cout << "转十进制(含前缀):\n"
              << std::showbase << std::dec << hex << std::endl;
    std::cout << "转二进制(含前缀):\n"
              << "0b" << std::bitset<8>(hex) << std::endl;  // 是的，二进制要手动添加，或者用函数什么的

    std::cout << "==== 整形后缀 ====" << std::endl;
    auto a = 100;       // int
    auto b = 100u;      // unsigned int
    auto c = 100l;      // long
    auto d = 100ul;     // unsigned long
    auto e = 100ll;     // long long
    auto f = 100ull;    // unsigned long long

    std::cout << "类型推断 : " << std::endl;
    std::cout << "100 =     " << typeid(a).name() << std::endl; // i是有符号整型
    std::cout << "100u =    " << typeid(b).name() << std::endl; // j是无符号整型
    std::cout << "100l =    " << typeid(c).name() << std::endl; // l是有符号长整型
    std::cout << "100ul =   " << typeid(d).name() << std::endl; // m是无符号长整型
    std::cout << "100ll =   " << typeid(e).name() << std::endl; // x是有符号长长整型
    std::cout << "100ull =  " << typeid(f).name() << std::endl; // y是无符号长长整型

    /*
        typeid().name()是一个用于查询编译器内部使用的名词的修饰后的结果的语句
        第一个括号里填要查询的变量，第二个括号里不填
    */

    std::cout << "==== 固定宽度的整型(需要头文件cstdint) ====" << std::endl;
    std::cout << "范围查询 : " << std::endl;
    std::cout << "int8_t为" << INT8_MIN << "到" << INT8_MAX << std::endl;
    std::cout << "int16_t为" << INT16_MIN << "到" << INT16_MAX << std::endl;
    std::cout << "int32_t为" << INT32_MIN << "到" << INT32_MAX << std::endl;
    std::cout << "int64_t为" << INT64_MIN << "到" << INT64_MAX << std::endl;

    std::cout << "无符号范围查询 : " << std::endl;
    std::cout << "uint8_t为 0" << " 到 " << UINT8_MAX << std::endl;
    std::cout << "uint16_t为 0" << " 到 " << UINT16_MAX << std::endl;
    std::cout << "uint32_t为 0" << " 到 " << UINT32_MAX << std::endl;
    std::cout << "uint64_t为 0" << " 到 " << UINT64_MAX << std::endl;

    
    std::cout << "大小查询 : " << std::endl;
    std::cout << "int8_t为 " << sizeof(int8_t) << "字节" << std::endl;
    std::cout << "int16_t为" << sizeof(int16_t) << "字节" << std::endl;
    std::cout << "int32_t为" << sizeof(int32_t) << "字节" << std::endl;
    std::cout << "int64_t为" << sizeof(int64_t) << "字节" << std::endl;

    /*
        int在不同平台的大小和表示的范围不同，long也是如此
        为了避免在跨平台时出现整数溢出的情况，所以有了固定宽度的整型
        int8_t、int16_t、int32_t、int64_t这几个在任意平台的大小和范围都不变
        同时，int8_t和char_t几乎一致
    */

    std::cout << "==== 整型溢出 ====" << std::endl;
    std::cout << "有符号整型溢出 : " << std::endl;
    int max_num = INT_MAX;
    std::cout << max_num << "(安全输出)" << std::endl;
    std::cout << "执行加法后结果为 " << max_num + 1 << "(未定义行为)" << std::endl;

    std::cout << "无符号整型溢出 : " << std::endl;
    uint nmax_num = UINT_MAX;   //  这里nmax_num的类型要注意了，UINT_MAX的值超过int的范围，所以要用uint
    std::cout << nmax_num << "(安全输出)" << std::endl;
    std::cout << "执行加法后结果为 " << nmax_num + 1 << "(回落至最小值后重新计算)" << std::endl;
    
    std::cout << "==== 整型提升 ====" << std::endl;
    std::cout << "小于int自动提升 : " << std::endl;
    short s1 = 20'000;
    short s2 = 30'000;
    int i1 = 40'000;
    int i2 = INT_MAX;
    int i3 = -15;
    uint u1 = 10;
    long l1 = 80'000;
    char c1 = 127;
    char c2 = -10;
    std::cout << "(s+s)运算进行后的类型为 " << typeid(s1 + s2).name() << "(s提升为i)" << std::endl;
    std::cout << "(s+i)运算进行后的类型为 " << typeid(s1 + i1).name() << "(s提升为i)" << std::endl;
    std::cout << "(c+c)运算进行后的类型为 " << typeid(c1 + c2).name() << "(c提升为i)" << std::endl;

    std::cout << "不小于int异类提升 : " << std::endl;
    std::cout << "(i+i)运算进行后类型为 "  << typeid(i1 + i2).name() << "(不提升)" << std::endl;
    std::cout << "(i+l)运算进行后类型为 "  << typeid(i1 + l1).name() << "(i提升为l)" << std::endl;

    std::cout << "符号相异自动提升 : "  << std::endl;
    std::cout << "(i+j)运算进行后的类型为 " << typeid(i1 + u1).name() << "(i提升为j)" << std::endl;

    std::cout << "混合提升范围为主 : " << std::endl;
    std::cout << "(j+l)运算进行后类型为 " << typeid(u1 + l1).name() << "(j提升为l)" << std::endl;

    std::cout << "符号相异，错误运算 : " << std::endl;
    std::cout << i3 + u1 << "(i3符号提升,值产生变化)" << "\n"
              << ((i3 < u1) ? true : false ) << "(i3发生变化,实际大于u1,输出false)" << std::endl;
              // (a ? b : c)为三分运算符，如果a对则输出b，如果a错则输出c

    /*
        整型提升是隐式转换，是为了防止整型溢出，但部分情况还是会溢出
        整型提升只是结果类型提升，变量类型不变
        整型提升发生在运算进行前，在运算前就已经将s提升至i，所以才有符号相异造成的错误运算
        整型提升在i之下自动提升为i,大于i则比较各项范围大小，提升至范围大的（范围取正数往无穷）
        在win平台中，l实际范围小于j，此时提升为m
        无符号整型的溢出行为比较特殊，负数提升至无符号时会发生值的变化，在运算和循环的时候要注意
        for(uint a = 100 ; a >= 0 ; a--)
        这实际上是死循环，因为a为j,不可能小于0
    */

    std::cout << "==== char(字符型整型)相关 ====" << std::endl;
    std::cout << "char变量 : " << std::endl;
    char ch1 = '5'; // 字符5
    char ch2 = 53;  // ASCII码为53的字符，实际上也是字符5
    char ch3 = '10';// 单引号里只能有一个字符，10是两个字符了。一个1一个0，是错误行为
    std::cout << ch1 << "(字符5)" << "\n" << ch2 << "(字符5)" << std::endl;
    std::cout << ch3 << "(并非字符10,这是多字符变量)" << std::endl;

    std::cout << "char的大小和范围 : " << std::endl;
    std::cout << "char的大小为 " << sizeof(char) << "字节" << std::endl;
    std::cout << "char的范围为 " << CHAR_MIN << "到" << CHAR_MAX << std::endl;
    std::cout << "uchar的范围为 0"<< "到" << UCHAR_MAX << std::endl;

    std::cout << "char的溢出 : " << std::endl;
    ch2 = 200;
    unsigned char ch4 = 300;
    std::cout << ch2 << "(发生溢出,未定义行为)" << std::endl;
    std::cout << ch4 << "(发生溢出，逻辑与无符号整型一致,不过显示的符号)" << std::endl;

    std::cout << "char的提升 : " << std::endl;
    auto sum = ch1 + i1;
    std::cout << "sum类型为 : " << typeid(sum).name() << "(提升为int)" << "\n"
              << "ch1类型为 : " << typeid(ch1).name() << "(不变)" << std::endl;
    
    /*
        char的整型提升过程实际为字符转ASCII码，然后以ASCII码当作数字做运算
        因为有整型提升，所以char的字符型也可以正常进行运算
    */

    std::cout << "需要记忆的几个ASCII码 : " << std::endl;
    std::cout << "数字0 : " << (int)'0' << std::endl; 
    std::cout << "字母a : " << (int)'a' << std::endl;
    std::cout << "字母A : " << (int)'A' << std::endl;

    std::cout << "ASCII中的转义字符 : " << std::endl;
    std::cout << "换行符 : " << "行1 \n 行2" << std::endl;
    std::cout << "横向制表符 : " << "表1 \t 表2"  << std::endl; // 使前方内容单独占据8格，左对齐

    std::cout << "=== char变体 ===" << std::endl;
    // char8_t u8t = u8'A';
    // char8_t同char相识，只能表示ASCII码相关，且所有字符均为1字节
    char16_t u16t = u'A';
    char16_t u16f = u'中';
    // char16_t可以表示中文等其他语言字符，其中，大部分字符都占2字节，特殊生僻字符占4字节
    char32_t U32t = U'A';
    char32_t U32f = U'中';
    char32_t U32G = U'🐶';
    // char32_t可以表示所有字符，包括表情，且所有字符一律四字节

    /*
        一个char/char8_t只有一字节空间，所以其无法表示占用空间超过一字节的中文等其他字符
        但是，可以通过数组的形式将多个char/char8_t组合起来表示一个中文或者其他字符
        如：char8_t u8f[] = u8'中'
        这里其实是通过数组让三个char8_t组合在一起形成了一个3字节的空间来容纳中文字符
        所以，要表示的话，对于char/char8_t来说，ASCII码相关占1字节，中文等其它语言占3字节，生僻和表情占4字节
    */

    std::cout << "==== bool(布尔类型)相关 ====" << std::endl;
    std::cout << "bool类型的类型简名为 : " << typeid(bool).name() << std::endl;
    std::cout << "bool类型的大小为 : " << sizeof(bool) << std::endl;
    bool b1 = true;
    bool b2 = false;
    bool b3 = 0;
    bool b4 = 100;
    bool b5 = -100;
    std::cout << "输出false和0,得到 : " << b2 << "和" << b3 << "(如果值为0/false,则输出为0)"  << std::endl;
    std::cout << "输出true、100和-100,得到 : " << b1 << "和" << b4 << "和" << b5 << "(如果值为true/不为0,则输出为1)" << std::endl;
    std::cout << "简述 : bool类型非0/false则得到1,反之得到0(1为真0为假)" << std::endl;

    std::cout << "bool类型的用途 : " << std::endl;
    std::cout << "用于计算 :" << std::endl;
    std::cout << "b1 * i1得 : " << (b1 * i1) << "(1 * 40'000)" << std::endl;
    std::cout << "b2 * i1得 : " << (b2 * i1) << "(0 * 40'000)" << std::endl;

    std::cout << "用于条件 : " << std::endl;
    int score = 76;
    bool Bscore = (score > 60);
    if (Bscore)
    {
        std::cout << "成绩高于60,及格!" << std::endl;
    }
    std::cout << "如果输出为1,则条件判断正确,反之,条件判断不正确。" << std::endl;

    return 0;
    
}