#include <iostream>
#include <vector>

int main()
{
    int n, t;
    std::cin >> n >> t;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        arr[i] = tmp;
    }

    int64_t sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != n - 1)
        {
            sum += std::min(arr[i + 1] - arr[i], t);
        }
        else
        {
            sum += t;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
