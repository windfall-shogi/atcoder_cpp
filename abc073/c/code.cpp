#include <iostream>
#include <unordered_map>

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> map;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        ++map[a];
    }

    int count = 0;
    for (const auto e : map)
    {
        if (e.second % 2 == 1)
        {
            ++count;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
