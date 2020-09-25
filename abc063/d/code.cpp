#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int64_t n, a, b;
    std::cin >> n >> a >> b;
    std::vector<int64_t> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());

    const int64_t c = a - b;
    int64_t min = (arr.front() + a - 1) / a;
    int64_t max = (arr.back() + b - 1) / b;
    if (min == max)
    {
        std::cout << min << std::endl;
        return 0;
    }

    int64_t t = (min + max) / 2;
    while (true)
    {
        const int64_t base = t * b;
        int64_t count = 0;
        for (const auto h : arr)
        {
            if (h <= base)
            {
                continue;
            }

            count += (h - base + c - 1) / c;
        }
        if (count > t)
        {
            min = t + 1;
        }
        else if (count <= t)
        {
            max = t;
        }

        if (min == max)
        {
            t = min;
            break;
        }
        else
        {
            if (min + 1 == max)
            {
                t = min;
            }
            else
            {
                t = (min + max) / 2;
            }
        }
    }

    std::cout << t << std::endl;
    return 0;
}
