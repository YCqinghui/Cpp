#include <iostream>
#include <string>
#include <cstring>

using std::string;

int main()
{
    std::cout << "string是标准库中的可变长字符串类型,比C风格字符串更方便且安全" << std::endl;

    std::cout << "\n====  string的初始化  ====" << std::endl;

    // 默认初始化
    string s1;   // 空字符串
    
    // 字面量初始化
    string s2 = "hello";
    string s3 ("hello world");

    // 拷贝初始化
    string s4 = s2;

    // 重复字符初始化
    string s5(5,'A');   // 输出5个A

    // 从字符串子串初始化
    string s6(s2,2,2);  // 从s2[2]开始抓取两个字符

    std::cout << "\ns1 = " << s1
              << "\ns2 = " << s2
              << "\ns3 = " << s3
              << "\ns4 = " << s4
              << "\ns5 = " << s5
              << "\ns6 = " << s6
              << std::endl;

    std::cout << "====  string的输入输出  ====" << std::endl;

    // 正常输入，读取时遇到空格就停止
    string name;
    std::cout << "请输入字符串 tandard library header file " << std::endl;
    std::cin >> name;
    std::cout << "输入结果为 : " << name <<  std::endl;

    // 整行读取，不受空格影响，但是不读取换行符，遇到换行符退出
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     // 清除缓冲区残留
    std::cout << "请输入字符串 tandard library header file " << std::endl;
    std::getline(std::cin , name);
    std::cout << "输入结果为 : " << name << std::endl;

    // 补充：逐个字符读取，不受空格、换行符影响，统计所有字符（用于char）
    char ch;
    int count = 0;
    int space = 0;
    while (std::cin.get(ch))
    {
        count++;
        if (ch == '\n')     // 单个转义字符需要用单引号，不能用双引号
        {
            space++;
            if (space == 2)
            {
                break;
            }
        }
        else
        {
            space = 0;
        }
    }
    std::cout << "输入字符数 : " << count << std::endl;
    
    /*
        注意，如果同时用了cin和getline进行输入的话，会发生问题
        cin正常输入之后会在缓冲区留下一个换行符'\n'，如果接下来再用getline的话，就会直接读取这个换行符
        导致后面会直接输出一个空的结果，而不是等待你输入
        要解决这个问题，首先不要这两个交换来用，就直接全用一个
        如果不小心都用了，那在cin和getline之间要加上
        std::cin.ignore()
        用于清空缓冲区残留的换行符
        同时，因为cin在读取输入的时候，遇到空格就会停止，所以如果用cin读取带空格的多个单词
        那最后只会读取到第一个空格前的部分，且第一个空格之后的部分会残留在缓冲区，和之前的换行符一个道理
        如果后面使用了getline，那就会直接读取缓冲区的这剩下的一部分
        这时候，就需要对缓冲区进行整行消除，需要使用
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        当然，其实只要注意不要混着来用就行
    */

    std::cout << "\n====  string的拼接和赋值  ====\n" << std::endl;

    string st1 = "hello";
    string st2 = "world";
    string st3,st4,st5,st6;

    // 拼接
    st3 = st1 + " " + st2;      // hello world
    st1 += " world";            // st1转换为hello world

    std::cout << "st3为 : " << st3
              << "\nst1为 : " << st1
              << std::endl;

    // 赋值
    st3 = st2;
    st4.assign(st2);        // 使用.assign函数进行赋值，效果同上，都是赋值，将s2的值赋予s3
    st5.assign(5,'A');      // 将s3的值变为'AAAAA'，=无法做到
    st6.assign(s2,2,2);     // 从st2[2]开始抓去两个字符用于赋值，=无法做到

    std::cout << "\nst3为 : " << st3
              << "\nst4为 : " << st4
              << "\nst5为 : " << st5
              << "\nst6为 : " << st6
              << std::endl;

    // 综上所述，可以看出，函数.assign的效果在一般赋值中和=差不多，但能做到许多=做不到的赋值

    std::cout << "\n====  string的大小和容量  ====\n" << std::endl;

    string str ("hello");

    std::cout << "大小为 : " << str.size() << std::endl;        // 五字节
    std::cout << "长度为 : " << str.length() << std::endl;      // 五，同上
    std::cout << "容量为 : " << str.capacity() << std::endl;
    std::cout << "是否为空 : " << str.empty() << std::endl;     // 0(false)

    // 1、在string中,size和lenght相同，但lenght只存在于string中，size更泛用
    // 2、容量是指预先给字符串分配的内存大小，通常大于字符串当前大小，如果字符串大小超过容量，则容量成倍增长

    str.resize(10);     // 调整内存为10，空出的位置填充"/0"
    std::cout << "\nresize后,str为 : " << str << std::endl;      // 显示的内容没变
    std::cout << "此时,str大小为 : " << str.size() << std::endl;    // 不过大小改变为10

    str.reserve(100);       // 手动预分配内存为100
    std::cout << "reserve后str内存大小为 : " << str.capacity() << std::endl;

    str.shrink_to_fit();    // 释放多余内存
    std::cout << "shrink_to_fit后str的内存大小为 : " << str.capacity() << std::endl;

    // 1、reserve的手动分配内存得到的内存大概率不会准确是你设置的，而是经过内部对齐和内部开销等考虑后变换过的，通常大一点
    // 2、shrink_to_fit的释放内存并不能精确释放到字符串大小，通常是释放到系统预设内存大小

    std::cout << "\n====  string的访问和修改  ====" << std::endl;

    string str1 = "hello";

    // 下标访问，不检查越界行为
    char c = str1[0];       // "H"
    char c1 = str1[4];      // "o"
    // char c2 = str1[10];     // 越界行为，本应报错，但该形式不检查越界行为

    std::cout << "\nc为 : " << c
              << "\nc1为 : " << c1
            //   << "\nc2为 : " << c2      // 未定义值，本应该报错，返回为空
              << std::endl;

    // at()安全访问，检查越界行为
    char c3 = str1.at(0);
    char c4 = str1.at(4);
    // char c5 = str1.at(10);       // 越界行为，进行检查后报错

    std::cout << "\nc3为 : " << c3
              << "\nc4为 : " << c4
            //   << "\nc5为 : " << c5      // 未定义值，检查并报错
              << std::endl;

    /*
        []和at()都是访问string中元素的手段，不过[]不检查越界行为，而at()会检查，更安全
        不过也因为at()会检查，所以性能稍慢，[]更快
        同时，对string其中元素的访问的返回值都是引用，避免过多的内存占用
    */

    // front()和back()
    char& first = str1.front();     // 返回str1的第一个元素
    char& last = str1.back();       // 返回str1的最后一个元素

    std::cout << "\nfirst的值为 : " << first
              << "\nlast的值为 : " << last
              << std::endl;

    // c_str(),将string字符返回C风格指针
    const char* cstr = str1.c_str();    // 返回的是const char*，只读，不可修改

    std::cout << "\ncstr的值为 : " << cstr
              << "\ncstr的长度为 : " << strlen(cstr)
              << std::endl;

    // 插入
    string str2 = "hello world";
    
    str2.insert(5," beautiful");    // 从str[5]开始插入" beautiful"
    str2.insert(0,"Hi ");        // 从str[0]开始插入"Hi " 
    str2.push_back('!');        // 在末尾插入'!'

    std::cout << "经过插入后的str2为 : " << str2 << std::endl;

    // 删除
    str2.erase(3,6);        // 从str2[3]的位置开始删除6个字符
    str2.pop_back();        // 删除末尾字符

    std::cout << "经过删除后的str2的值为 : " << str2 << std::endl;

    str2.clear();       //  清空字符串

    if (str2.empty())
    {
        std::cout << "str2为空" << std::endl;
    }

    // 部分修改
    str2 = "hello world";
    str2.replace(6,5,"wulianqiyu");     // 从str2[6]开始更改五个字符，也可以理解为将这五个字符替换为别的,不限长度

    std::cout << "修改后str2的值为 : " << str2 << std::endl;

    // 还有一些对于string中字符的改动可以使用cctype头文件中的函数，可以去学习下

    std::cout << "\n====  string的查找  ====" << std::endl;

    string str3 = "tandard library header file";

    // find:从左往右查找第一个，索引为从左往右
    size_t pos1 = str3.find("header");      //  16
    size_t pos2 = str3.find("r");       // 5

    std::cout << "\npos1 : " << pos1
              << "\npos2 : " << pos2
              << std::endl;

    // rfind:从右往左查找第一个，索引依旧为从左往右
    size_t pos3 = str3.rfind("library");
    size_t pos4 = str3.rfind("d");

    std::cout << "\npos3 : " << pos3    // 8
              << "\npos4 : " << pos4    // 19
              << std::endl;

    // 虽然rfind是从右往左寻找第一个，但是因为C++的索引都是从左往右，所以要索引还是从左往右

    // find_first_of，查找字符串中符合该字符串中元素的第一个元素位置，想要从右往左就把first换成last
    size_t pos5 = str3.find_first_of("ryu");
    std::cout << "\nstr3中第一个'ryu'之中的字母的位置为 : " << pos5 << std::endl;

    string str4 = "ddddddddkasty";

    // find_first_not_of，查找字符串中不符合该字符串中元素的第一个元素的位置，想要从右往左就把first换成last
    size_t pos6 = str4.find_first_not_of("d");
    std::cout << "str4中第一个不是'd'的元素的位置为 : " << pos6 << std::endl;

    // find和find_first_of的区别在于一个一个是查找一整个需求字符串，一个是查找需求字符串中的元素

    // string::npos表示未找到需求字符
    size_t pos7 = str4.find("m");
    if (pos7 == string::npos)
    {
        std::cout << "未找到需求字符" << std::endl;
    }

    std::cout << "\n====  string的子串和比较  ====" << std::endl;

    // 子串，根据元素位置提取子串
    std::cout << "\nstr3中的第二个单词为 : " << str3.substr(8,7) << std::endl;    // 从str3[8]开始提取七个字符
    std::cout << "str3中最后一个单词为 : " << str3.substr(str3.find("f")) << std::endl;     // 从str3.find("f")到结尾

    // string的查找可以配合提取子串

    // 比较
    string sr1 = "apple";
    string sr2 = "banana";
    string sr3 = "Apple";
    string sr4 = "apple";
    string sr5 = "appLe";

    std::cout << "\nsr1 == sr2 : " << (sr1 == sr2)
              << "\nsr1 < sr2 : " << (sr1 < sr2)        // 根据遇到的第一个不同的字母的ascii码进行比较
              << "\nsr1 > sr2 : " << (sr1 > sr2)
              << "\nsr1 > sr5 : " << (sr1 > sr5)
              << "\nsr1 < sr5 : " << (sr1 < sr5)        // 第一个不同的字母，谁ascii码大谁大
              << "\nsr3 == sr1 : " << (sr3 == sr1)
              << "\nsr4 == sr1 : " << (sr4 == sr1)      // 只有完全相同才相同
              << std::endl; 

    // compare的比较,正数表示大于，负数表示小于，0表示等于

    int result1 = sr1.compare(sr2);
    int result2 = sr1.compare(sr3);
    int result3 = sr1.compare(sr4);
    std::cout << "\nsr1 vs sr2 : " << result1   // -1，a和b的ascii码差值为1
              << "\nsr1 vs sr3 : " << result2   // 32，a和A的ascii码差值为32
              << "\nsr1 vs sr4 : " << result3   // 0，二者相同ascii没有差异
              << std::endl;

    // compare的返回值实际上是二者的首个不同字符的ascii码的差值，可以用来比较，也可以用来排序

    // compare比较子串和别的字符串
    int result4 = sr1.compare(1,4,"hello");     // 从sr1[1]开始提取四个字符作为子串比较"hello"
    std::cout << "\npple vs hello : " << result4 << std::endl;

    int result5 = sr1.compare(1,4,sr2);     // 从sr1[1]开始提取四个字符作为子串比较sr2
    std::cout << "\npple vs banana : " << result5 << std::endl;

    // compare比较两个子串
    int result6 = sr1.compare(1,4,sr2,2,3);     // 从sr1[1]开始取四个字符作子串比较从sr2[2]开始取三个字符作子串
    std::cout << "\npple vs nan : " << result6 << std::endl;

    std::cout << "\n====  综合示例————查找文件名  ====" << std::endl;

    string filename = "string.cpp";
    size_t pos = filename.rfind(".");
    if (pos != string::npos)
    {
        std::cout << "文件名为 : " << filename.substr(0,pos) << std::endl;
    }

    return 0;

}