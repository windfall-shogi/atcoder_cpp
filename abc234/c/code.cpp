#include <iostream>

int main()
{
    uint64_t K;
    std::cin >> K;

    bool flag = false;
    for (int i = 63; i >= 0; --i)
    {
        bool bit = (K & (1ULL << i)) != 0;
        if (bit)
        {
            flag = true;
        }
        if (flag)
        {
            std::cout << (bit ? 2 : 0);
        }
    }
    std::cout << std::endl;
    return 0;
}
