#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    int n, k;
    std::cin >> n >> k;
    --k;
    std::vector<int> ps(n);
    for (int i = 0; i < n; ++i)
    {
        int p1, p2, p3;
        std::cin >> p1 >> p2 >> p3;
        ps[i] = p1 + p2 + p3;
    }

    std::vector<int> buffer(ps.begin(), ps.end());
    std::nth_element(buffer.begin(), buffer.begin() + k, buffer.end(), std::greater<int>());
    for (int i = 0; i < n; ++i)
    {
        std::cout << (ps[i] + 300 >= buffer[k] ? "Yes" : "No") << std::endl;
    }

    return 0;
}
