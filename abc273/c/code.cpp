#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> as(n), bs(n);
    std::unordered_map<int64_t, int> count;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
        bs[i] = as[i];
        ++count[as[i]];
    }
    std::sort(bs.begin(), bs.end());
    bs.erase(std::unique(bs.begin(), bs.end()), bs.end());

    for (int i = 0; i < n; ++i)
    {
        if (i >= bs.size())
        {
            std::cout << 0 << std::endl;
        }
        else
        {
            std::cout << count.at(bs[bs.size() - 1 - i]) << std::endl;
        }
    }

    return 0;
}
