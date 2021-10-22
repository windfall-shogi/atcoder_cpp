#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }

    const auto it = std::find(as.begin(), as.end(), 1);
    const auto d_head = std::distance(as.begin(), it);

    const int l = k - 1;
    const int count_head = (d_head + l - 1) / l;

    const int d_tail = n - (l * count_head + 1);
    const int count_tail = (d_tail + l - 1) / l;

    std::cout << count_head + count_tail << std::endl;

    return 0;
}
