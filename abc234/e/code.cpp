#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<int> v;
    int64_t X = 0;
    for (char c : s)
    {
        v.emplace_back(c - '0');
        X = X * 10 + c - '0';
    }

    if (s.size() <= 2)
    {
        std::cout << X << std::endl;
        return 0;
    }

    {
        bool ok = true;
        const int delta = v[1] - v[0];
        for (int64_t i = 2; i < s.size(); ++i)
        {
            const int tmp = v[i] - v[i - 1];
            if (tmp != delta)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            std::cout << X << std::endl;
            return 0;
        }
    }

    int64_t N = s.size(); // 作りたい桁数
    int start = v[0];
    int64_t ans = 0;
    bool ok = false;
    while (true)
    {
        std::vector<int> buffer(N);
        buffer[0] = start;
        for (int delta = -4; delta <= 4; ++delta)
        {
            ok = true;
            ans = start;
            for (int64_t i = 1; i < N; ++i)
            {
                buffer[i] = buffer[i - 1] + delta;
                if (buffer[i] < 0 || buffer[i] >= 10)
                {
                    ok = false;
                    break;
                }
                ans = ans * 10 + buffer[i];
            }
            if (ok)
            {
                if (ans < X)
                {
                    ok = false;
                }
                else
                {
                    break;
                }
            }
        }
        ++start;
        if (start >= 10)
        {
            ++N;
            start = 1;
        }

        if (ok)
        {
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
