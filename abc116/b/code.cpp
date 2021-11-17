#include <iostream>

int main()
{
    int s;
    std::cin >> s;
    int index = 1;
    while (s != 4 && s != 2 && s != 1)
    {
        if (s % 2 == 0)
        {
            s /= 2;
        }
        else
        {
            s = 3 * s + 1;
        }
        ++index;
    }

    std::cout << index + 3 << std::endl;

    return 0;
}
