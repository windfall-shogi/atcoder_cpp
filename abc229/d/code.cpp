#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string S;
    int K;
    std::cin >> S;
    std::cin >> K;

    int count = 0;
    std::vector<int64_t> buf(S.size());
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] == 'X')
        {
            ++count;
        }
        buf[i] = count;
    }
    if (S.size() - count <= K)
    {
        std::cout << S.size() << std::endl;
        return 0;
    }

    int ans = 0;
    int l = 0, r;
    while (true)
    {
        r = l + K - 1;
        while (r < S.size())
        {
            if (l == 0)
            {

                if (buf[r] + K > r + 1 || (r + 1 < S.size() && S[r + 1] == 'X'))
                {
                    ++r;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (buf[r] - buf[l - 1] + K > r - l + 1 || (r + 1 < S.size() && S[r + 1] == 'X'))
                {
                    ++r;
                }
                else
                {
                    break;
                }
            }
        }
        ans = std::max(ans, r - l + 1);

        bool done = false;
        if (S[l] == 'X')
        {
            while (true)
            {
                ++l;
                if (buf.back() - buf[l - 1] + K == S.size() - l + 1)
                {
                    break;
                }
                if (l >= S.size())
                {
                    done = true;
                    break;
                }
                if (S[l] != 'X')
                {
                    break;
                }
            }
        }
        else
        {
            while (true)
            {
                ++l;
                if (buf.back() - buf[l - 1] + K == S.size() - l + 1)
                {
                    break;
                }
                if (l >= S.size())
                {
                    done = true;
                    break;
                }
                if (S[l] == 'X')
                {
                    break;
                }
            }
        }

        if (done)
        {
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
