#include <iostream>
#include <vector>
#include <string>

int main ()
{
    std::vector<std::string> names {"x","xx","xxx"};
    std::vector<int> hp {100,200,300};
    int killCount = 0;
    
    std::cout << "请输入‘1/2/3’选择攻击对象,输入'0'退出" << std::endl;
    while (true)
    {
        int attackTarget;       // 攻击对象
        int damage = 9;         // 伤害
        std::cin >> attackTarget;
        if (attackTarget == 1)
        {
            auto it = std::find(names.begin(),names.end(),"x");     // 得到的it是迭代器
            int index = it - names.begin();     // 由迭代器转换为索引，index是索引
            hp[index] -= damage;
            std::cout << "怪物x受到攻击，剩余血量为 : " << hp[index] << std::endl;
            if (hp[index] <= 0)
            {
                names.erase(it);
                hp.erase(index + hp.begin());
                names.push_back("x");
                hp.push_back(100);
                killCount++;
                std::cout << "怪物x已死亡,生成新的怪物x" << std::endl;
            }
        }
        if (attackTarget == 2)
        {
            auto it = std::find(names.begin(),names.end(),"xx");     // 得到的it是迭代器
            int index = it - names.begin();     // 由迭代器转换为索引，index是索引
            hp[index] -= damage;
            std::cout << "怪物xx受到攻击，剩余血量为 : " << hp[index] << std::endl;
            if (hp[index] <= 0)
            {
                names.erase(it);
                hp.erase(index + hp.begin());
                names.push_back("xx");
                hp.push_back(200);
                killCount++;
                std::cout << "怪物xx已死亡,生成新的怪物xx" << std::endl;
            }
        }
        if (attackTarget == 3)
        {
            auto it = std::find(names.begin(),names.end(),"xxx");     // 得到的it是迭代器
            int index = it - names.begin();     // 由迭代器转换为索引，index是索引
            hp[index] -= damage;
            std::cout << "怪物xxx受到攻击，剩余血量为 : " << hp[index] << std::endl;
            if (hp[index] <= 0)
            {
                names.erase(it);
                hp.erase(index + hp.begin());
                names.push_back("xxx");
                hp.push_back(300);
                killCount++;
                std::cout << "怪物xxx已死亡,生成新的怪物xxx" << std::endl;
            }
        }
        if (attackTarget == 0)
        {
            std::cout << "该轮攻击结束" << std::endl;
            break;
        }    
    }
    std::cout << "击杀怪物数量为 : " << killCount <<std::endl;

    return 0;
    
}