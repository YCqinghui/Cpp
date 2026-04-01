#include <iostream>

int main()
{
    // const的含义
    std::cout << "const表示常量,被其修饰的变量不可改变" << std::endl;

    std::cout << "\n==== const的基本用法 ====\n" << std::endl;

    int i = 100;    // 变量
    const int i1 = 100;     // const修饰的int常量

    i++;        // 成立，变量可改变
    // i1++;    不成立，变量不可改变

    std::cout << "变量 i = " << i
              << "常量 const i1 = " << i1
              << std::endl;

    std::cout << "\n==== const与指针 ====\n" << std::endl;

    int ia = 10;
    const int ib = 100;
    const int ic = 1000;

    // 普通指针
    int* pa = &ia;      

    // 指向常量的指针
    const int* pb = &ib; 
    // *pb = 101        错误，指向常量的指针承诺不修改其对象的值，不可改变其值
        pb = &ic;    // 允许，指向常量的指针本身是普通指针，可以修改指向的对象
    
    /*
        指向常量的指针能否选择变量作为对象？
    */

    // 常量指针
    int* const pc = &ia; 
       *pc = 11;     // 允许，常量指针指向变量，可以修改对象值
    //  pc = &i;        不允许，常量指针指向的对象从定义之初便已经固定，不可改变
    
    /*
        常量指针能否选择常量作为对象？
    */

    // 指向常量的常量指针
    const int* const pd = &ib;  
    //  pd = 1001;      不允许，常量指针承诺不修改其对象的值，不可修改值
    //  pd = &ia;       不允许，常量指针不可修改其指向的对象

    std::cout << "其实指向常量的指针并非只能指向常量，也可以指向变量，只是承诺不修改其对象的值" << std::endl;

    /*
        要分辨具体是什么指针，主要也就是看const的位置
        由于对于指针来说const只影响身后一个字段，所以，
        const int* 这里便是一个int常量，因为其后面跟着的是int，修饰的是int，代表int值不可变
        也可以说是这是一个指针，指向const int
        int* const 这里便是一个常量指针，因为其后面跟着的是变量名，修饰的是变量，说明这个变量不可变
        也可以说这是一个const指针，指向int  
    */

    std::cout << "\n==== 指针和引用 ====" << std::endl;

    int id = 100;
    const int ie = 1000;

    // 普通引用
    int& r = id;
    r = 101;        // 可以通过引用修改对象值

    // 常量引用
    const int& ra = id;     // 常量引用可以引用变量
                            // 常量引用不区分底层const和顶层const，可以用来正常初始化和赋值
    // ra = 102;    // 这是不允许的，常量引用不允许之间通过引用修改对象值
    id = 102;       // 但是可以通过直接修改对象的值来更改常量引用的值

    const int& rb = ie;     // 常量引用也可以直接引用常量，不过这时候引用的值就没法变了

    std::cout << "\n常量引用也并非只能引用常,只是限定了引用所能参与的操作" << std::endl;

    // 常量引用绑定右值
    int&& rc = 100;                 // 原本只有右值引用可以绑定右值
    const int& rd = 100;            // 但常量引用也可以直接绑定右值
    const int& rf = id + 1000;      // 算式也是右值

    std::cout << "\n==== 顶层const和底层const ====" << std::endl;

    int ig = 10;

    // 顶层const
    int* const pe = &ig;
    std::cout << "\n顶层const即本身是const,像这里的指针本身是const,所以是顶层" << std::endl;

    const int ij = 100;     // 这里也是顶层，ij本身是const

    // 底层const
    const int* pf = &ig;
    std::cout << "\n底层const即是把对象当作const"
              << "\n这里的pf是底层const,也就是其把对象当作const,也就是常量,但对象本身是不是常量无所谓"
              << "\n当然,如果对象本身不是常量,就可以说是增加底层const的操作"
              << std::endl;
    
    const int& re = ig; // 常量引用也是底层const，因为常量引用特性是不可改变其引用对象的值，也就是把对象当作const
                        // 概念上是底层，但实际上不区分，也不是即顶层又底层，单纯不区分
    int set = re;       // 可以正常给非const进行初始化和赋值


    // 即是顶层也是底层
    const int* const pg = &ig;

    std::cout << "==== 注意事项 ====" << std::endl;

    std::cout << "\n顶层const在拷贝、也就是赋值操作或者初始化操作的时候,不受const影响"
              << "\n也就是说,虽然顶层const是const常量,但是可以赋值或初始化给变量（类型相同）"
              << "\n因为顶层const在进行初始化和操作时,其本身是很难因为它初始化活着复制的对象而改变"
              << "\n这也就是删去顶层const操作"
              << std::endl;

    int* ph = pe;   // 按理来讲，ph为非const不能选择const作为对象，但是pe是顶层const，不受影响,并且双方都是int*，类型相同
                    // 这里就相当于ph拷贝pe的地址，就等于也是指向了pe指向的对象
                    // 这也就是去掉顶层const
    pa = pe;        // 拷贝操作也是同理
    const int num = 100;    // 顶层const
    int num1 = num;     // 给非const初始化

    std::cout << "\n不过,像初始化二级指针这种操作是不行的，因为双方类型不匹配(一个一级指针一个二级指针)"
              << "\n引用也是同理,一个普通的引用无法引用一个常量int,因为一个是int&,一个是int"
              << "\n而且初始化二级指针要进行一个取地址的操作,这不算在初始化和拷贝里"
              << "\n并且通过二级指针是能够改变一级指针本身的,所以是不行的"
              << std::endl;

    // int** pi = &pe;  这个是不行的，一个int**一个int*，类型不同，且进行里取地址操作，不合规
    // int& rg = num    这个也不行，类型不匹配，一个是int&，一个是int

    std::cout << "\n但是,底层const就不同了"
              << "\n如果你赋值或初始化的值为底层const,那你本身也必须是底层const"
              << "\n因为底层const把其对象的值当作const,是不可变的"
              << "\n所以,如果你给一个非const弄一个const对象,你很多时候就会误认为这个值是可以改变的,然后对一个const进行改变"
              << "\n这明显是不合规的,所以不行"
              << "\n当然,如果你想让一个底层const赋值或者初始化给一个非const,这叫做删去底层const操作"
              << std::endl;

    const int* pj = &ig;
    // int* pk = pj;       这个就不行，因为pj是底层const，而pk是非const，这样做是删去底层const

    std::cout << "\n可以删去顶层const、可以增加底层const,但不能删去底层const" << std::endl;

    return 0;

}