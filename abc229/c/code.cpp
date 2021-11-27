#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>

int main()
{
    int N, W;
    std::cin >> N >> W;
    using Data = std::pair<int, int>;
    std::vector<Data> data(N);
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        data[i] = std::make_pair(a, b);
    }
    std::sort(data.rbegin(), data.rend());

    int64_t ans = 0;
    for (const auto &e : data)
    {
        const int64_t weight = std::min<int64_t>(W, e.second);
        ans += weight * e.first;

        W -= weight;
        if (W == 0)
        {
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
