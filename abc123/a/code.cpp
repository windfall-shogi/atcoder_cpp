#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> xs;
    int k;
    for (int64_t i = 0; i < xs.size(); ++i)
    {
        std::cin >> xs[i];
    }
    std::cin >> k;

    bool ok = true;
    for (int64_t i = 0; i < xs.size() - 1; ++i)
    {
        for (int64_t j = i + 1; j < xs.size(); ++j)
        {
            if (xs[j] - xs[i] > k)
            {
                ok = false;
                break;
            }
        }
    }

    std::cout << (ok ? "Yay!" : ":(") << std::endl;
    return 0;
}
