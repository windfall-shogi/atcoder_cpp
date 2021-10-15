#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> xs(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        xs[i] = std::make_pair(x, i);
    }

    std::sort(xs.begin(), xs.end());
    
    std::vector<int> order(n);
    for(int i=0;i<n;++i){
        order[xs[i].second] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        const int j=order[i];
        if (j < n / 2)
        {
            std::cout << xs[n / 2].first << std::endl;
        }
        else
        {
            std::cout << xs[n / 2 - 1].first << std::endl;
        }
    }

    return 0;
}
