#include <iostream>

int main()
{
    int y, m, d;
    std::scanf("%d/%d/%d", &y, &m, &d);
    if (m <= 4)
    {
        std::cout << "Heisei" << std::endl;
    }
    else
    {
        std::cout << "TBD" << std::endl;
    }
    return 0;
}
