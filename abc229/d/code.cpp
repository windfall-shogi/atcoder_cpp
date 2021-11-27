#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string S;
    int K;
    std::cin >> S;
    std::cin >> K;

    const int n = static_cast<int>(S.size());
    std::vector<int64_t> buf(S.size() + 1);
    for (int i = 0; i < S.size(); ++i)
    {
        // 書き換え対象の.を数えた方がこの後の処理が簡単
        if (S[i] == '.')
        {
            buf[i + 1] = buf[i] + 1;
        }
        else
        {
            buf[i + 1] = buf[i];
        }
    }

    int ans = 0;
    int r = 0;
    for (int l = 0; l < n; ++l)
    {
        while (r <= n && buf[r] - buf[l] <= K)
        {
            ++r;
        }
        ans = std::max(ans, r - l - 1);
    }

    std::cout << ans << std::endl;

    return 0;
}
