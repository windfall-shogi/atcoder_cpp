#include <iostream>
#include <vector>

int main()
{
    int n, x;
    std::cin >> n >> x;
    --x;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> as[i];
        --as[i];
    }
    std::vector<bool> known(n);

    int ans = 1;
    known[x] = true;

    int k = x;
    while (true)
    {
        const int y = as[k];
        if (known[y])
        {
            break;
        }

        known[y] = true;
        ++ans;

        k = y;
    }

    std::cout << ans << std::endl;

    return 0;
}
