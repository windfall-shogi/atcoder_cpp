#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string str;
    std::cin >> str;
    const int n = str.size();
    std::vector<int> current(n, -n * 2), next(n, 0);
    current[0] = 0;
    for (const char c : str)
    {
        if (c == 'g')
        {
            next[0] = current[1] + 1;
            for (int i = 1; i < n - 1; ++i)
            {
                next[i] = std::max(current[i + 1] + 1, current[i - 1]);
            }
            next[n - 1] = current[n - 2];
        }
        else
        {
            // c == 'p'
            next[0] = current[1];
            for (int i = 1; i < n - 1; ++i)
            {
                next[i] = std::max(current[i + 1], current[i - 1] - 1);
            }
            next[n - 1] = current[n - 2] - 1;
        }
        current.swap(next);
    }
    const auto it = std::max_element(current.begin(), current.end());
    std::cout << *it << std::endl;

    return 0;
}
