#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> e_array(n), w_array(n);
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            e_array[i] = 0;
        }
        else
        {
            e_array[i] = e_array[i - 1] + (s[i - 1] == 'W' ? 1 : 0);
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (i == n - 1)
        {
            w_array[i] = 0;
        }
        else
        {
            w_array[i] = w_array[i + 1] + (s[i + 1] == 'E' ? 1 : 0);
        }
    }

    int ans = 2 * n;
    for (int i = 0; i < n; ++i)
    {
        const int v = e_array[i] + w_array[i];
        if (v < ans)
        {
            ans = v;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
