#include <iostream>
#include <queue>
#include <vector>
#include <numeric>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int64_t> arr(3 * n);
    for (int i = 0; i < 3 * n; ++i)
    {
        std::cin >> arr[i];
    }

    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int>> q1;
    std::priority_queue<int64_t> q2;
    std::vector<int64_t> max1(n + 1), max2(n + 1);

    int64_t sum1 = std::accumulate(arr.begin(), arr.begin() + n, 0ll);
    int64_t sum2 = std::accumulate(arr.rbegin(), arr.rbegin() + n, 0ll);
    for (int i = 0; i < n; ++i)
    {
        q1.emplace(arr[i]);
        q2.emplace(arr[3 * n - i - 1]);
    }
    max1[0] = sum1;
    max2[n] = sum2;

    for (int i = 0; i < n; ++i)
    {
        const auto top1 = q1.top();
        if (top1 < arr[n + i])
        {
            // 交換したほうがいい
            sum1 += arr[n + i] - top1;
            q1.pop();
            q1.emplace(arr[n + i]);
        }
        max1[i + 1] = sum1;

        const auto top2 = q2.top();
        if (top2 > arr[2 * n - i - 1])
        {
            // 交換したほうがいい
            sum2 += arr[2 * n - i - 1] - top2;
            q2.pop();
            q2.emplace(arr[2 * n - i - 1]);
        }
        max2[n - i - 1] = sum2;
    }

    int64_t d = max1[n] - max2[n];
    for (int i = 0; i < n; ++i)
    {
        d = std::max(d, max1[i] - max2[i]);
    }

    std::cout << d << std::endl;
    return 0;
}
