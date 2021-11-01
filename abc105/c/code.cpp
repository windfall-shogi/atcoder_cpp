#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> v;
    while (n != 0)
    {
        if (n % 2 != 0)
        {
            --n;
            v.emplace_back(1);
        }
        else
        {
            v.emplace_back(0);
        }
        n /= -2;
    }

    if (v.empty())
    {
        v.emplace_back(0);
    }

    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
