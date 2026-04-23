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
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 随机访问
    auto it = vec.begin() + 5;     // 指向vec[5]

    std::cout << *it << std::endl;      // 6

    // 距离
    int dist = it - vec.begin();        // 迭代怒相减，得到索引

    std::cout << "it到vec首位的距离为 : " << dist << std::endl;


    std::cout << "====  迭代器类型  ====" << std::endl;

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
    


}