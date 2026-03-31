#include <iostream>

int main()
{
    // 指针的含义
    std::cout << "指针式存储内存地址的变量，指向另一个变量的内存地址" << std::endl;
    
    std::cout << "\n==== 指针的基础操作 ====" << std::endl;

    std::cout << "\n1、定义指针" << std::endl;

    int i = 100;
    int* i_ptr = &i;    // &i其实表示的就是i的内存地址，而这个表达的意思就是创建指针i_prt指向i的内存地址
    // double i_ptr1 = &i   ⚠️，指针指向的对象和指针的数据类型必须相同

    int* s,d;   // *是类型修饰符，只作用于后一个对象，这里只有s是指针，d是int

    // 由于指针本身指向的是地址，所以直接输出指针得到的是其指向的变量的地址
    // 如果想输出其指向的对象的值，需要将指针进行解引用
    std::cout << "\n2、输出指针" << std::endl;

    std::cout << "\n指针i_ptr指向的对象的值为 : " << *i_ptr     // 通过解引用符*对指针进行解引用
              << "\n指针i_ptr的值为 : " << i_ptr
              << std::endl;

    std::cout << "\n3、通过指针修改变量" << std::endl;

    *i_ptr = 12345;

    std::cout << "\n修改后指针指向的值为 : " << *i_ptr << std::endl;
    std::cout << "此时变量i的值为 : " << i << std::endl;
    std::cout << "变量i的值变为" << i << ",说明成功通过指针修改变量的值" << std::endl;

    std::cout << "\n4、修改指针" << std::endl;

    int i1 = 1000;
    i_ptr = &i1;

    std::cout << "\n变量i的内存地址为 : " << &i << std::endl;
    std::cout << "变量i1的内存地址为 : " << &i1 << std::endl;
    std::cout << "修改后指针i_ptr指向的内存地址为 : " << i_ptr << std::endl;
    std::cout << "此时地址和i1一致,说明成功修改了指针的指向" << std::endl;

    std::cout << "\n5、空指针" << std::endl;

    // 两种定义空指针的方式
    int* null_p = nullptr;
    int* null_p1 = 0;
    if (null_p == nullptr)
    {
        std::cout << "\n指针可以为空" << std::endl;
    }
    if (null_p1 == nullptr)
    {
        std::cout << "\n指针可以为空" << std::endl;
    }



    std::cout << "\n==== 指针的分类 ====" << std::endl;


    std::cout << "\n1、指向变量的指针" << std::endl;

    int i2 = 123;
    int* i2_ptr = &i2;

    std::cout << "\n指针i2_ptr指向的对象的值为 : " << *i2_ptr     
              << "\n指针i2_ptr的值为 : " << i2_ptr
              << "\ni2的内存地址为 : " << &i2
              << std::endl;


    std::cout << "\n2、指向数组的指针" << std::endl;

    int arr[] = {1 , 2 , 3 , 4 , 5};
    int* p = arr;       // ⚠️，这里的指针p指向的是数组arr的首元素

    std::cout << "\n数组arr中的元素分别为 : " << std::endl;

    for (int i = 0 ; i < 5 ; i++)
    {
        std::cout << *(p + i);
        if (i == 4)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << ",";
        }
    }

    // 指向数组的指针其实是指向数组内部首个元素的地址，并且这个地址可以进行运算，
    // +1就是数组中往后推一个元素，也就是第二个元素，-1就是往前推一个元素

    std::cout << "\n指针不仅可以指向数组里的元素,还可以指向整个数组 : " << std::endl;

    int (*parr)[5] = &arr;

    std::cout << "\n数组arr里的第三个元素为 : " << (*parr)[2] << std::endl;

    // (*parr)[5]为指针数组，在定义时，指针数组里的元素个数要和被指向的数组里的元素个数一样
    // 指向整个数组的指针数组可以当作该数组来使用，不过需要注意，要带上小括号


    std::cout << "\n3、指向指针的指针" << std::endl;

    // 与引用不同，指针有自己独立的内存，所以可以有指向指针的指针，也就是多级指针

    int i3 = 100;
    int* p1 = &i3;
    int** pp1 = &p1;    // 二级指针
    int*** ppp1 = &pp1; // 三级指针

    std::cout << "\n指针p1指向的对象的值为 : " << *p1
              << "\n指针p1的值为 : " << p1
              << "\n二级指针pp1指向的对象的值为 : " << *pp1
              << "\n二级指针pp1的值为 : " << pp1
              << "\n三级指针ppp1指向的对象的值为 : " << *ppp1
              << "\n三级指针ppp1的值为 : " << ppp1
              << "\n当然,我们也可以通过多重解引用返回最开始的值 :"
              << "\n三级解引用***ppp1 = " << ***ppp1
              << "\n二级解引用**pp1 = " << **pp1
              << std::endl;

    // 要返回初始值，三级指针就需要解引用三次，也就是三个解引用符
    // 毕竟，三级指针指向的是二级指针的地址，解引用得到二级指针的值，也就是一级指针的地址
    // 再解引用就是得到一级指针的值，也就是变量i3的地址
    // 再解引用就得到了i3的值

    std::cout << "\n==== 指针的运算 ====" << std::endl;

    // 指针的运算指的是指向数组的指针

    int arr1[] = {1,2,3,4,5,6};
    int* z = arr1;

    std::cout << "\n1、指针算数" << std::endl;

    std::cout << "\narr[0]为 : " << *z << std::endl;
    std::cout << "arr[2]为 : " << *(z + 2) << std::endl;
    std::cout << "arr[4]为 : " << *(z + 4) << std::endl;

    std::cout << "\n2、指针自增" << std::endl;

    z++;        //  等同于z+1;
    std::cout << "\n" << *z << std::endl;

    std::cout << "\n3、指针相减" << std::endl;

    int* z1 = &arr1[3];
    std::cout << "\nz1和z之间的距离为 : " << (z1 - z) << "个元素" << std::endl;

    // 指向同一个数组的指针相减得到的是两个指针所指向的元素在数组里的距离

    std::cout << "\n4、指针比较" << std::endl;

    if (z1 > z)
    {
        std::cout << "\n指针z1在指针z后面" << std::endl;
    }

    return 0;

}