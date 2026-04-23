#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 

// 编写一个程序，完成以下功能：

// 输入学生人数 n
// 依次输入 n 个学生的成绩（整数）
// 将所有成绩存入 vector<int> 中
// 计算并输出：

// 总分
// 平均分（保留两位小数）
// 最高分
// 最低分
// 及格人数（≥60分）
// 将成绩从高到低排序并输出

int main()
{
    int studentCount = 0;
    int grade = 0;
    std::vector<int> grades;

    std::cout << "请输入学生人数 : " << std::endl;
    std::cin >> studentCount;

    std::cout << "请依次输入学生成绩 : " << std::endl;
    while (std::cin >> grade)
    {
        grades.push_back(grade);
        if (grades.size() == studentCount)
        {
            break;
        }
    }

    //  计算
    double totalScore = 0;
    double averageScore = 0;
    int maxScore = 0;
    int minScore = 0;
    int passCount = 0;

    for (int& i : grades)
    {
        totalScore += i;
        if (i >= 60)
        {
            passCount++;
        }
    }
    std::cout << std::fixed << std::setprecision(2);
    averageScore = totalScore / studentCount;
    maxScore = *std::max_element(grades.begin(),grades.end());
    minScore = *std::min_element(grades.begin(),grades.end());

    std::cout << "总分为 : " << totalScore << std::endl;
    std::cout << "平均分为 : " << averageScore << std::endl;
    std::cout << "最高分为 : " << maxScore << std::endl;
    std::cout << "最低分为 : " << minScore << std::endl;
    std::cout << "及格人数为 : " << passCount << std::endl;

    std::cout << "以下为成绩的倒序输出（高到低） : " << std::endl;
    std::sort(grades.rbegin(),grades.rend());
    for (int& i : grades)
    {
        std::cout << i << " ";
    }

    return 0;

}