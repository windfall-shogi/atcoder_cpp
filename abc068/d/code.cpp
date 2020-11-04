#include <iostream>
#include <array>

int main()
{
    int64_t k;
    std::cin >> k;

    // [2, 50]ならいくつでもいい
    // もしかすると数列の要素の制限に引っ掛かるかも
    constexpr int64_t n = 50;
    std::array<int64_t, n> arr;

    const int64_t q = k / n;
    const int64_t r = k % n;
    for (int64_t i = 0; i < n; ++i)
    {
        arr[i] = q - r + i;
    }
    for (int64_t i = 0; i < r; ++i)
    {
        arr[i] += n + 1;
    }

    std::cout << n << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i];
        if (i < n - 1)
        {
            std::cout << ' ';
        }
        else
        {
            std::cout << std::endl;
        }
    }

    return 0;
}
