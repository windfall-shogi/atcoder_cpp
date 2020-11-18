#include <iostream>
#include <map>
#include <functional>

int main()
{
    int n;
    std::cin >> n;
    std::map<int, int, std::greater<int>> m;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        m[tmp] += 1;
    }

    int64_t len[2] = {0, 0};
    int index = 0;
    for (const auto e : m)
    {
        if (e.second >= 4)
        {
            if (index == 0)
            {
                len[0] = len[1] = e.first;
            }
            else
            {
                len[1] = e.first;
            }
            index = 2;
            break;
        }
        else if (e.second >= 2)
        {
            len[index] = e.first;
            ++index;
            if (index == 2)
            {
                break;
            }
        }
    }

    std::cout << len[0] * len[1] << std::endl;
    return 0;
}
