#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;

    int32_t result = k;
    for (int i = 0; i < n - 1; ++i)
    {
        result *= k - 1;
    }

    std::cout << result << std::endl;
    return 0;
}
