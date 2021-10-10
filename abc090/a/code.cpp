#include <iostream>

int main()
{
    char cs[3][3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> cs[i][j];
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        std::cout << cs[i][i];
    }
    std::cout << std::endl;

    return 0;
}
