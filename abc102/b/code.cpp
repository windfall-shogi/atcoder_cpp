#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    std::sort(as.begin(), as.end());

    std::cout << as.back() - as.front() << std::endl;

    return 0;
}
