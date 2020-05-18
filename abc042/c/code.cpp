#include <iostream>
#include <set>
#include <vector>
#include <string>

bool search(const std::string &s, const std::set<int> &ok_set,
            const int d, const bool only_upper, std::vector<int> &result)
{
    const int v = s[d] - '0';
    bool tmp_only_upper = only_upper;
    for (const int o : ok_set)
    {
        if (tmp_only_upper && o < v)
        {
            continue;
        }
        result[d] = o;
        if (d == s.size() - 1)
        {
            return true;
        }
        else
        {
            const bool status = search(s, ok_set, d + 1, only_upper && v == o, result);
            if (status)
            {
                return true;
            }
            tmp_only_upper = true;
        }
    }
    return false;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    // trueなら使える
    std::vector<bool> flags(10, true);
    std::set<int> ok_set;
    for (int i = 0; i < k; ++i)
    {
        int tmp;
        std::cin >> tmp;
        flags[tmp] = false;
    }
    for (int i = 0; i < 10; ++i)
    {
        if (flags[i])
        {
            ok_set.emplace(i);
        }
    }

    const std::string s = std::to_string(n);
    std::vector<int> result(s.size());

    const bool status = search(s, ok_set, 0, true, result);
    if (status)
    {
        for (const int v : result)
        {
            std::cout << v;
        }
        std::cout << std::endl;
    }
    else
    {
        // 一桁増える
        bool zero = false;
        for (const int v : ok_set)
        {
            if (v == 0)
            {
                zero = true;
                continue;
            }
            if (zero)
            {
                std::cout << v;
                for (int i = 0; i < s.size(); ++i)
                {
                    std::cout << 0;
                }
                std::cout << std::endl;
            }
            else
            {
                for (int i = 0; i < s.size() + 1; ++i)
                {
                    std::cout << v;
                }
                std::cout << std::endl;
            }
            break;
        }
    }

    return 0;
}
