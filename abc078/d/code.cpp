#include <iostream>
#include <vector>

int main()
{
    int64_t n, z, w;
    std::cin >> n >> z >> w;
    std::vector<int64_t> as(n);
    for (int64_t i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }
    
    if (n == 1)
    {
        std::cout << std::abs(w - as.back()) << std::endl;
    }
    else
    {
        std::cout << std::max(std::abs(w - as.back()), std::abs(as[n - 2] - as[n - 1])) << std::endl;
    }
    return 0;
}
