#include <iostream>
#include <deque>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::deque<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
    }
    std::sort(as.begin(), as.end());
    std::unique(as.begin(), as.end());

    int ans = 0;
    while (!as.empty())
    {
        if (as.front() == ans + 1)
        {
            ++ans;
            as.pop_front();
        }
        else if (as.size() >= 2)
        {
            as.pop_back();
            as.pop_back();
            ++ans;
        }
        else
        {
            break;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
