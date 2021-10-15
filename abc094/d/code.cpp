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

    const int ai = *std::max_element(as.begin(), as.end());
    int aj = -1;
    int v = -1;
    for (const int a : as)
    {
        if (a == ai)
        {
            continue;
        }

        if (v < std::min(a, ai - a))
        {
            aj = a;
            v = std::min(a, ai - a);
        }
    }

    std::cout << ai << ' ' << aj << std::endl;

    return 0;
}
