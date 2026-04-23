#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "vector是C++标准库中的动态数组，可以自动扩容，大小可变" << std::endl;

    std::cout << "\n====  vector的初始化  ====\n" << std::endl;

    // 1，默认初始化为空
    std::vector<int> v1;        // 无元素，默认为空

    // 2，指定大小的初始化
    std::vector<int> v2 (10);   // 指定大小为10，但未指定值，则默认空置位置用0填充，也就是10个'0'
    std::cout << "v2为 : ";
    for (int c : v2)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // 3、指定大小和值的初始化
    std::vector<int> v3 (10 , 5);   // 指定大小为10，值为5，也就是10个‘5’
    std::cout << "v3为 : ";
    for (int c : v3)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // 4、列表初始化
    std::vector<int> v4 = {1,2,3,4,5,6,7,8,9,0};
    std::vector<int> v5 {1,2,3,4,5,6,7,8,9,0};
    std::cout << "v4为 : ";
    for (int c : v4)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;std::cout << "v5为 : ";
    for (int c : v5)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // 5、拷贝初始化
    std::vector<int> v6 = v5;
    std::cout << "v6为 : ";
    for (int c : v6)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::cout << "\n====  vector的基本操作  ====\n" << std::endl;

    std::vector<int> v;

    std::cout << "1、添加元素" << std::endl;

    // 1、末尾添加
    v.push_back(10);        // v = {10}
    v.push_back(20);        // v = {10,20}
    v.push_back(30);        // v = {10,20,30}

    // 2、指定位置插入
    v.insert(v.begin(),5);       // 在v[0]插入5，v = {5,10,20,30}
    v.insert(v.begin()+2,15);    // 在v[2]插入15，v = {5,10,15,20,30}

    // 3、批量插入
    v.insert(v.end()-1,{21,22,23,24,25,26,27,28,29});

    std::cout << "v : ";
    for (int& c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // vector支持自动扩容，而数组不支持，这是一个优势所在

    std::cout << "\n2、删除元素" << std::endl;

    // 1、删除末尾元素
    v.pop_back();

    // 2、删除指定位置元素（括号里的值需要是迭代器或者索引）
    v.erase(v.begin());         // 删除v[0];
    v.erase(v.begin()+1);       // 删除v[1];

    // 3、批量删除元素（删除区间元素）
    v.erase(v.begin()+2,v.end());   // 将v[2]到末尾的元素全部删除

    std::cout << "v : ";
    for (int& c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // 4、清除所有元素
    v.clear();

    /*
        string可以直接以整数作为索引来直接定位修改元素，但vector不行
        vector需要以迭代器(begin()和end())作为锚点来定位修改元素
    */


    std::cout << "3、访问元素" << std::endl;

    v.insert(v.begin(),{10,20,30,40,50});

    // 1、下标访问（无边界检查）
    int a = v[0];       // 10
    int b = v[3];       // 40
    // int c = v[20];      // 超出边界，但不报错，输出为空白？

    // 2、.at访问（有边界检查）
    int d = v.at(0);
    int e = v.at(3);
    // int f = v.at(20);       // 超出边界，会报错

    std::cout << "a = " << a
              << "\nb = " << b
              << "\nd = " << d
              << "\ne = " << e
              << std::endl;

    // 3、front()/back()
    int first = v.front();      // v[0]，也就是10
    int last = v.back();        // v[4]，也就是50

    std::cout << "\nfirst = " << first
              << "\nlast = " << last
              << std::endl;

    // 4、利用指针访问（同数组）
    int* prt = v.data();        // prt指向vector容器的首个元素

    std::cout << "\n*prt = " << *prt            // 指向v[0]
              << "\n*(prt+2) = " << *(prt+2)    // 指向v[2]
              << "\n*(prt+4) = " << *(prt+4)    // 指向v[4]
              << std::endl;


    std::cout << "\n====  vector的大小和容量  ====\n" << std::endl;

    std::cout << "v的大小为 : " << v.size() << std::endl;
    std::cout << "v的容量为 : " << v.capacity() << std::endl;
    std::cout << "v是否为空 : " << v.empty() << std::endl;

    // 预分配空间
    v.reserve(100);
    std::cout << "reserve后的容量为 : " << v.capacity() << std::endl;

    // 更改大小
    v.resize(30);       // 将大小调整为30，超出原本大小的部分用0填充
    v.resize(35,90);    // 将大小调整为35，超出原本大小的部分用90填充
    
    std::cout << "更改大小后v为 : ";
    for (int& c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // 释放多余容量
    v.shrink_to_fit();
    std::cout << "释放多余容量后v的容量为 : " << v.capacity() << std::endl;

    /*
        访问大小和容量的操作，vector与string差不多，
        不过，在内存的预分配上，vector可以准确分配设置的内存，而string则会有向上浮动
        释放多余内存也是，vector可以准确释放到大小，而string只能释放到系统分配内存
    */

    std::cout << "\n====  vector的一些基本函数操作  ====\n" << std::endl;
    // 依赖于algorithm头文件

    v.clear();
    v.insert(v.begin(),{2,5,8,3,4,9,1,7,6,0});
    v.resize(10);

    // 排序
    std::sort(v.begin(),v.end());   // 将其中元素从小到大进行排序
    std::cout << "正序 : ";
    for (int& c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::sort(v.rbegin(),v.rend());     // 倒序排序
    std::sort(v.begin(),v.end(),std::greater<int>());   // 同上，倒序排序

    // 反转
    std::reverse(v.begin(),v.end()); // 注：reverse是将当前vector中的排序直接倒过来，不会进行整理排序
    for (int& c : v)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // 查找
    auto it = std::find(v.begin(),v.end(),3);       // 返回的int是迭代器
    if (it != v.end())
    {
        std::cout << "v中数字3的位置为 : " << (it - v.begin()) << std::endl;   // 也就是v[it - v.begin()] = 3
    }

    // 统计
    v.push_back(9);
    int count = std::count(v.begin(),v.end(),9);      // 查找数组中数字9的数量
    std::cout << "v中数字9的数量为 : " << count << std::endl;

    // 最值
    v.pop_back();
    int max = *std::max_element(v.begin(),v.end());
    int min = *std::min_element(v.begin(),v.end());

    std::cout << "\nv中最大的元素为 : " << max
              << "\nv中最小的元素为 : " << min
              << std::endl;



    std::cout << "\n====  二维vector(二维动态数组)  ====\n" << std::endl;

    std::cout << "二维vector可以理解为vector的vector,也就是外层vector里的每一个元素都是一个vector" << std::endl;

    std::cout << "\n====  二维vector的初始化方式  ====" << std::endl;

    // 1、默认初始化（空）
    std::vector<std::vector<int>> vec1;

    // 2、指定行数不定列数初始化
    std::vector<std::vector<int>> vec2 (5);      // 有五行0，但每行都是空的vector

    // 3、指定行数和列数的初始化，但不给值，默认所有值为0
    std::vector<std::vector<int>> vec3(3,std::vector<int>(4));  //  三行四列，值均为0

    // 4、列表初始化
    std::vector<std::vector<int>> vec4
    {
        {1},
        {1,2},
        {1,2,3},
        {1,2,3,4},
        {1,2,3,4,5},
        {1,2,3,4,5,6}
    };
    //  vector支持不同长度的行

    std::cout << "vec4 : " << std::endl;
    for (int i = 0 ; i < vec4.size() ; i++)
    {
        for (int j = 0 ; j < vec4[i].size() ; j++)
        {
            std::cout << vec4[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n====  二维vector的基本操作  ====\n" << std::endl;

    std::vector<std::vector<int>> mat;

    std::cout << "1、添加" << std::endl;

    // 添加新空行(在末尾)
    mat.push_back(std::vector<int>());

    // 添加元素(在末尾)
    mat[0].push_back(1);        // 在第一行末尾添加元素1
    mat[0].push_back(2);        // 在第一行末尾添加元素2

    // 添加新行并初始化(给予内容)
    mat.push_back({1,2,3,4});

    // 通过一维vector添加新行
    std::vector<int> row {1,2,3,4,5,6};
    mat.push_back(row);

    std::cout << "经过添加后mat为 : " << std::endl;
    for (int i = 0 ; i < mat.size() ; i++)
    {
        for (int j = 0 ; j < mat[i].size() ; j++)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "2、删除" << std::endl;

    // 删除末行
    mat.pop_back();     // 删除最后一行

    // 删除任意行
    mat.erase(mat.begin()+1);   // 删除第二行

    // 删除任意元素
    mat[0].erase(mat[0].begin()+1);  // 删除第一行的第二个元素

    // 清空所有行
    mat.clear();

    std::cout << "3、获取大小" << std::endl;

    // 通过循环构建一个二维动态数组
    for (int i = 0 ; i < 100 ; i++)
    {
        mat.push_back(std::vector<int>());
        for (int j = 0 ; j <= i ; j++)
        {
            mat[i].push_back(j);
        }
    }

    std::cout << "mat的行数为 : " << mat.size() << std::endl;
    for (int i = 0 ; i < mat.size() ; i++)
    {
        std::cout << "mat的第" << i+1 << "行有" << mat[i].size() << "个元素" << std::endl; 
    }


    std::cout << "\n====  遍历二维vector  ====\n" << std::endl;

    // 下标访问
    for (int i = 0 ; i < mat.size() ; i++)
    {
        for (int j = 0 ; j < mat[i].size() ; j++)
        {
            std::cout << mat[i][j];
            if (j != i)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // 范围for访问
    for (auto& row : mat)           
    {
        for (int& col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl; 
    }

    // 注意，二维vector的外层类型是std::vector<int>，而不是int，类型选择auto更好
    // 进行范围for访问的话，一般选择的类型是auto&，auto是为了避免类型选择出错，&是为了节省内存
    // 如果不用引用的话，就要把原二维动态数组拷贝一遍，增大内存开销，而引用不会
    
    return 0;

}