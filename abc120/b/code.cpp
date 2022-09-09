#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

int main()
{
    int a, b, k;
    std::cin >> a >> b >> k;

    std::vector<int> candidates;
    for (int i = std::min(a, b); i > 0; --i)
    {
        if (a % i == 0 && b % i == 0)
        {
            candidates.push_back(i);
        }
    }
    std::cout << candidates[k - 1] << std::endl;

    return 0;
}