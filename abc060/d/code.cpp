#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

int main()
{
    int n, w;
    std::cin >> n >> w;
    std::vector<int> w_arr(n), v_arr(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp_w, tmp_v;
        std::cin >> tmp_w >> tmp_v;
        w_arr[i] = tmp_w;
        v_arr[i] = tmp_v;
    }

    std::vector<std::vector<int64_t>> values(4);
    for (int i = 0; i < n; ++i)
    {
        const int j = w_arr[i] - w_arr[0];
        values[j].push_back(v_arr[i]);
    }
    for (int i = 0; i < 4; ++i)
    {
        std::sort(values[i].begin(), values[i].end(), std::greater<>());
    }
    std::vector<int64_t> weights(4);
    for (int i = 0; i < 4; ++i)
    {
        weights[i] = w_arr[0] + i;
    }

    int max_value = 0;
    for (size_t i = 0; i <= values[0].size(); ++i)
    {
        const int64_t w0 = weights[0] * i;
        if (w0 > w)
        {
            break;
        }
        const int64_t v0 = std::accumulate(values[0].begin(), values[0].begin() + i, 0ll);
        for (size_t j = 0; j <= values[1].size(); ++j)
        {
            const int64_t w1 = weights[1] * j;
            if (w0 + w1 > w)
            {
                break;
            }
            const int64_t v1 = std::accumulate(values[1].begin(), values[1].begin() + j, 0ll);
            for (size_t k = 0; k <= values[2].size(); ++k)
            {
                const int64_t w2 = weights[2] * k;
                if (w0 + w1 + w2 > w)
                {
                    break;
                }
                const int64_t v2 = std::accumulate(values[2].begin(), values[2].begin() + k, 0ll);
                for (size_t l = 0; l <= values[3].size(); ++l)
                {
                    const int64_t w3 = weights[3] * l;
                    if (w0 + w1 + w2 + w3 > w)
                    {
                        break;
                    }
                    const int64_t v3 = std::accumulate(values[3].begin(), values[3].begin() + l, 0ll);
                    const int64_t v = v0 + v1 + v2 + v3;
                    if (v > max_value)
                    {
                        max_value = v;
                    }
                }
            }
        }
    }

    std::cout << max_value << std::endl;
    return 0;
}
