#include <iostream>
#include <cctype>
#include <string>

int main()
{
    std::cout << "cctype是C++中的字符分类及转换函数库，用于判断字符类型以及大小写转换" << std::endl;

    std::cout << "\n====  字符判断函数  ====\n" << std::endl;

    // 1、isalnum(c)，c为字母或数字时为真
    std::string str = "aA5 ,\t.";

    std::cout << "isalnum : " << std::endl;
    for (char c : str)
    {
        if (isalnum(c))
        {
            std::cout << c << "是字母或者数字" << std::endl;
        }
        else
        {
            std::cout << c << "不是字母或数字" << std::endl;
        }
    }
    std::cout << std::endl;

    // 2、isalpha(c)，c为字母时为真
    std::cout << "isalpha : " << std::endl;
    for (char c : str)
    {
        if (isalpha(c))
        {
            std::cout << c << "是字母" << std::endl;
        }
        else
        {
            std::cout << c << "不是字母" << std::endl;
        }
    }
    std::cout << std::endl;

    // 3、isdigit(c)，c为十进制数字时为真
    std::cout << "isdigit : " << std::endl;
    for (char c : str)
    {
        if (isdigit(c))
        {
            std::cout << c << "是十进制数字" << std::endl;
        }
        else
        {
            std::cout << c << "不是十进制数字" << std::endl;
        }
    }
    std::cout << std::endl;

    // 4、isxdigit(c)，c为十六进制数字时为真(0-9, a-f, A-F)
    std::cout << "isxdigit : " << std::endl;
    for (char c : str)
    {
        if (isxdigit(c))
        {
            std::cout << c << "是十六进制数字" << std::endl;
        }
        else
        {
            std::cout << c << "不是十六进制数字" << std::endl;
        }
    }
    std::cout << std::endl;

    // 5、islower(c)，c为小写字母时为真
    std::cout << "islower : " << std::endl;
    for (char c : str)
    {
        if (islower(c))
        {
            std::cout << c << "是小写字母" << std::endl;
        }
        else
        {
            std::cout << c << "不是小写字母" << std::endl;
        }
    }
    std::cout << std::endl;

    // 6、isupper(c)，c为大写字母时为真
    std::cout << "isupper : " << std::endl;
    for (char c : str)
    {
        if (isupper(c))
        {
            std::cout << c << "是大写字母" << std::endl;
        }
        else
        {
            std::cout << c << "不是大写字母" << std::endl;
        }
    }
    std::cout << std::endl;

    // 7、isspace(c)，c为空白字符时为真（' '、'\t'、'\n'、'\r'、'\f'、'\v'）
    std::cout << "isspace : " << std::endl;
    for (char c : str)
    {
        if (isspace(c))
        {
            std::cout << c << "是空白字符" << std::endl;
        }
        else
        {
            std::cout << c << "不是空白字符" << std::endl;
        }
    }
    std::cout << std::endl;

    // 8、ispunct(c)，c为标点符号时为真
    std::cout << "ispunct : " << std::endl;
    for (char c : str)
    {
        if (ispunct(c))
        {
            std::cout << c << "是标点符号" << std::endl;
        }
        else
        {
            std::cout << c << "不是标点符号" << std::endl;
        }
    }
    std::cout << std::endl;

    // 9、iscntrl(c)，c为控制字符时为真（'\n', '\t', '\0'）
    std::cout << "iscntrl : " << std::endl;
    for (char c : str)
    {
        if (iscntrl(c))
        {
            std::cout << c << "是控制字符" << std::endl;
        }
        else
        {
            std::cout << c << "不是控制字符" << std::endl;
        }
    }
    std::cout << std::endl;

    // 10、isprint(c)，c为可打印字符时为真（'a', ' ', '5'），含空格
    std::cout << "isprint : " << std::endl;
    for (char c : str)
    {
        if (isprint(c))
        {
            std::cout << c << "是可打印字符（含空格）" << std::endl;
        }
        else
        {
            std::cout << c << "不是可打印字符（含空格）" << std::endl;
        }
    }
    std::cout << std::endl;

    // 11、isgraph(c)，c为可打印字符时为真（'a', '5'，' ' 为假）不含空格
    std::cout << "isgraph : " << std::endl;
    for (char c : str)
    {
        if (isgraph(c))
        {
            std::cout << c << "是可打印字符（不含空格）" << std::endl;
        }
        else
        {
            std::cout << c << "不是可打印字符（不含空格）" << std::endl;
        }
    }
    std::cout << std::endl;


    std::cout << "\n====  字符转换函数  ====\n" << std::endl;

    std::string str1 = "ADSJHFgasgdgqgFaskjdGHJbad";

    // 1、tolower(c)，小写照旧，大写字母转换为小写字母
    // 2、toupper(c)，大写照旧，小写字母转换为大写字母
    for (char& c : str1)
    {
        if (isupper(c))
        {
            c = tolower(c);
        }
        else if (islower(c))
        {
            c = toupper(c);
        }
    }
    std::cout << "转换后的str1为 : " << str1 << std::endl;

    //  注：字符转换函数返回转换后的字符，但不直接改变字符串里的字符，需要进行赋值操作
    
}