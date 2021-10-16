#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main()
{
    int64_t n, c;
    std::cin >> n >> c;
    std::vector<int64_t> xs(n), vs(n);
    for (int64_t i = 0; i < n; ++i)
    {
        std::cin >> xs[i] >> vs[i];
    }

    // AtCoderのサーバーで即値で0を指定する部分でコンパイルエラーになったので、対策
    constexpr int64_t zero=0;

    // 右回り
    std::vector<int64_t> v_clock(n), max_clock1(n), max_clock2(n);
    std::partial_sum(vs.begin(), vs.end(), v_clock.begin());
    for (int64_t i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            max_clock1[i] = std::max(v_clock[i] - xs[i], zero);
            max_clock2[i] = std::max(v_clock[i] - 2 * xs[i], zero);
        }
        else
        {
            max_clock1[i] = std::max(v_clock[i] - xs[i], max_clock1[i - 1]);
            max_clock2[i] = std::max(v_clock[i] - 2 * xs[i], max_clock2[i - 1]);
        }
    }

    // 左回り
    std::vector<int64_t> v_counter_clock(n), max_counter_clock1(n), max_counter_clock2(n);
    std::partial_sum(vs.rbegin(), vs.rend(), v_counter_clock.rbegin());
    for (int64_t i = n - 1; i >= 0; --i)
    {
        if (i == n - 1)
        {
            max_counter_clock1[i] = std::max(v_counter_clock[i] - (c - xs[i]), zero);
            max_counter_clock2[i] = std::max(v_counter_clock[i] - 2 * (c - xs[i]), zero);
        }
        else
        {
            max_counter_clock1[i] = std::max(v_counter_clock[i] - (c - xs[i]), max_counter_clock1[i + 1]);
            max_counter_clock2[i] = std::max(v_counter_clock[i] - 2 * (c - xs[i]), max_counter_clock2[i + 1]);
        }
    }

    int64_t max = 0;
    for (int64_t i = 0; i < n; ++i)
    {
        max = std::max({max_clock1[i], max_counter_clock1[0], max});
        if (i != n - 1)
        {
            max = std::max(max_clock2[i] + max_counter_clock1[i + 1], max);
        }
        if (i != 0)
        {
            max = std::max(max_counter_clock2[i] + max_clock1[i - 1], max);
        }
    }

    std::cout << max << std::endl;

    return 0;
}
