#include <iostream>
#include <unordered_map>

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        ++m[tmp];
    }

    int count = 0;
    for (const auto &e : m)
    {
        if (e.first > e.second)
        {
            count += e.second;
        }
        else if (e.first < e.second)
        {
            count += e.second - e.first;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
