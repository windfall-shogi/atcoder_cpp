#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> data(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        data[i] = std::make_pair(a, b);
    }
    std::sort(data.begin(), data.end());

    int count = 0;
    int64_t value = 0;
    for (const auto &e : data)
    {
        const int k = std::min(e.second, m - count);
        value += static_cast<int64_t>(k) * e.first;
        count += k;
        if (count >= m)
        {
            break;
        }
    }

    std::cout << value << std::endl;
    return 0;
}
