#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    std::vector<int> count(n);
    count[0] = 0;
    for (int64_t i = 1; i < s.size(); ++i)
    {
        if (s[i - 1] == 'A' && s[i] == 'C')
        {
            count[i] = count[i - 1] + 1;
        }
        else
        {
            count[i] = count[i - 1];
        }
    }

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        --l;
        --r;
        std::cout << count[r] - count[l] << std::endl;
    }
    return 0;
}
