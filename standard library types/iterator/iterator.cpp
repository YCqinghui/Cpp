#include <iostream>
#include <vector>
#include <string>

int main()
{
    // 什么是迭代器？
    std::cout << "迭代器是C++中用于遍历容器中元素的通用工具，行为像指针，可指向容器中的元素" << std::endl;

    // 操作
    std::cout << "====  迭代器的基本操作  ====" << std::endl;

    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};

    auto begin = vec.begin();       // 指向vec中第一个元素
    auto end = vec.end();           // 指向vec中最后一个元素

    // 迭代器遍历
    for (auto it = vec.begin() ; it < vec.end() ; it++)     // 对迭代器进行递增，每增一次指向的位置就后移一个元素
    {
        // 迭代器的输出，类似指针的输出，需要解引用，但迭代器不是指针
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 随机访问
    auto it = vec.begin() + 5;     // 指向vec[5]

    std::cout << *it << std::endl;      // 6

    // 距离
    int dist = it - vec.begin();        // 迭代怒相减，得到索引

    std::cout << "it到vec首位的距离为 : " << dist << std::endl;


    std::cout << "\n====  迭代器类型  ====\n" << std::endl;

    // 1、随机访问
    // 支持迭代器所有操作
    // 适用于vector,arry,deque

    // 2、双向访问
    // 仅支持递增和递减
    // 适用于list,map,set

    // 3、单向访问
    // 仅支持递增
    // 适用于forward_list

    // 4、输入输出
    // 仅支持基本读写
    // 适用于istream,ostream
    

    std::cout << "\n====  迭代器的分类  ====\n" << std::endl;

    std::vector<int> v = {10,20,30,40,50};

    // 普通迭代器
    auto it1 = v.begin();
    std::cout << "it1 = " << *it1 << std::endl;     // 10

    // 常量迭代器（只读，不可修改）
    auto it2 = v.cbegin();
    // *it2 = 100;  不可行
    std::cout << "it2 = " << *it2 << std::endl;     // 10

    // 反向迭代器(从后往前)
    auto it3 = v.rbegin();
    std::cout << "it3 = " << *it3 << std::endl;     // 50

    std::cout << "\n====  迭代器失效  ====\n" << std::endl;

    // 在容器发生改动后，在改动前的迭代器将在改动之后失效，需重新获得迭代器
    auto it4 = v.begin();

    // 扩容
    v.push_back(60);
    // v进行了扩容，原迭代器it4失效
    // std::cout << *it4 << std::endl;  危险行为

    // 删除
    v.erase(v.begin() + 2);
    // 删除了v[2]，原迭代器it4依旧会失效
    // std::cout << *it4 << std::endl;      // 依旧危险

    // 重新获取迭代器
    auto it5 = v.begin();
    std::cout << "it5 = " << *it5 << std::endl;

    std::cout << "\n====  迭代器与索引的转换  ====\n" << std::endl;

    // 迭代器转索引
    auto im = v.begin() + 2;
    auto idx = im - v.begin();
    std::cout << "索引为 : " << idx << std::endl;
    std::cout << "索引指向 : " << v[idx] << std::endl;

    // 索引转迭代器
    auto ix = idx + v.begin();
    std::cout << "迭代器指向 : " << *ix << std::endl;

    // 注：不同容器的迭代器不能混用

    return 0;

}