#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::string str;
    std::cin >> str;

    std::vector<int> counter(n);
    int c = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == '(')
        {
            ++c;
        }
        else
        {
            --c;
        }
        counter[i] = c;
    }

    const int min = *std::min_element(counter.begin(), counter.end());
    if (min < 0)
    {
        for (int i = 0; i < -min; ++i)
        {
            std::cout << '(';
        }
    }
    std::cout << str;
    for (int i = 0; i < counter.back() - std::min(min, 0); ++i)
    {
        std::cout << ')';
    }
    std::cout << std::endl;

    return 0;
}
