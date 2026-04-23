#include <iostream>
#include <vector>
#include <string>

int main ()
{
    std::vector<std::vector<std::string>> mat;
    int x = 2;
    int count = 9;
    for (int i = 0 ; i < 9 ; i ++)
        {
            mat.push_back(std::vector<std::string>());
            if (i < 5)
            {
                int z = i;
                while (z > 0)
                    {
                        mat[i].push_back(" ");
                        z--;
                    }
                for (int y = 0 ; y < count ; y++)
                    {
                        mat[i].push_back("*");
                    }
                if (count >= 3)
                {
                    count -= 2;
                }
            }
            else
            {
                int z = i - x;
                while (z > 0)
                    {
                        mat[i].push_back(" ");
                        z--;
                    }
                x += 2;
                count += 2;
                for (int y = 0 ; y < count ; y++)
                    {
                        mat[i].push_back("*");
                    }
            }
        }
    for (std::vector<std::string>& i : mat)
        {
            for (std::string& y : i)
                {
                    std::cout << y;
                }
            std::cout << std::endl;
        }
}