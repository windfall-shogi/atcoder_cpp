#include <iostream>

char TABLE[2][2];
int main()
{
    int count = 0;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            std::cin >> TABLE[i][j];
            if (TABLE[i][j] == '#')
            {
                ++count;
            }
        }
    }

    bool ok = count >= 3;
    if (count == 2)
    {
        ok = !((TABLE[0][0] == '#' && TABLE[1][1] == '#') ||
               (TABLE[1][0] == '#' && TABLE[0][1] == '#'));
    }

    std::cout << (ok ? "Yes" : "No") << std::endl;

    return 0;
}
