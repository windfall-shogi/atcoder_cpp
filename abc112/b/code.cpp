#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, T;
    std::cin >> N >> T;
    std::vector<int> cs;
    cs.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        int c, t;
        std::cin >> c >> t;
        if (t <= T)
        {
            cs.emplace_back(c);
        }
    }

    if (cs.empty())
    {
        std::cout << "TLE" << std::endl;
        return 0;
    }

    std::sort(cs.begin(), cs.end());
    std::cout << cs.front() << std::endl;

    return 0;
}
