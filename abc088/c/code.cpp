#include <iostream>
#include <array>

bool check(const std::array<std::array<int, 3>, 3> &grid)
{
    for (int i = 1; i < 3; ++i)
    {
        const int tmp = grid[i][0] - grid[0][0];
        for (int j = 1; j < 3; ++j)
        {
            if (grid[i][j] - grid[0][j] != tmp)
            {
                return false;
            }
        }
    }

    for (int j = 1; j < 3; ++j)
    {
        const int tmp = grid[0][j] - grid[0][0];
        for (int i = 1; i < 3; ++i)
        {
            if (grid[i][j] - grid[i][0] != tmp)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    std::array<std::array<int, 3>, 3> grid;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> grid[i][j];
        }
    }

    /*
    a1+b1 a1+b2 a1+b3
    a2+b1 a2+b2 a2+b3
    a3+b1 a3+b2 a3+b3
    */

    std::cout << (check(grid) ? "Yes" : "No") << std::endl;
    return 0;
}
