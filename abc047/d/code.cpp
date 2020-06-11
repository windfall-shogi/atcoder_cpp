#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main()
{
    int n, t;
    std::cin >> n >> t;
    std::vector<int> list;
    list.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        list.push_back(tmp);
    }

    std::vector<int> min_list(n);
    int a = list[0];
    for (int i = 0; i < n; ++i)
    {
        if (list[i] < a)
        {
            a = list[i];
        }
        min_list[i] = a;
    }

    std::unordered_map<int, int> profits;
    int max_profit = 0;
    for (int i = 0; i < n; ++i)
    {
        const int tmp = list[i] - min_list[i];

        max_profit = std::max(max_profit, tmp);
        ++profits[tmp];
    }

    std::cout << profits[max_profit] << std::endl;
    return 0;
}
