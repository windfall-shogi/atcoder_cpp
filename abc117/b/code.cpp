#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> ls(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> ls[i];
    }

    const auto it_max = std::max_element(ls.begin(), ls.end());
    int sum = 0;
    for (auto it = ls.begin(); it != ls.end(); ++it)
    {
        if (it != it_max)
        {
            sum += *it;
        }
    }

    std::cout << (sum > *it_max ? "Yes" : "No") << std::endl;

    return 0;
}
