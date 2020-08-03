#include <iostream>
#include <vector>
#include <algorithm>

constexpr int N = 5000;
constexpr int K = 5000;

bool Solve(const std::vector<int> &arr, const int skip_index, const int k)
{
    std::vector<bool> current(k + 1), next(k + 1);
    current[0] = true;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (i == skip_index)
        {
            continue;
        }

        const int a = arr[i];
        for (int j = 0; j <= k; ++j)
        {
            // 使わない場合
            next[j] = next[j] || current[j];
            // 使う場合
            next[std::min(k, j + a)] = next[std::min(k, j + a)] || current[j];
        }

        current.swap(next);
    }

    const int a = arr[skip_index];
    for (int i = std::max(k - a, 0); i < k; ++i)
    {
        if (current[i])
        {
            // 必要
            return true;
        }
    }
    // 不要
    return false;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        arr[i] = tmp;
    }
    std::sort(arr.begin(), arr.end());

    int first = 0;
    int last = n;
    do
    {
        int i = (first + last) / 2;
        if (Solve(arr, i, k))
        {
            // 必要なので[first, i)の範囲
            last = i;
        }
        else
        {
            // 不要なので[i + 1, last)の範囲
            first = i + 1;
        }
    } while (first != last);
    std::cout << last << std::endl;
    return 0;
}
