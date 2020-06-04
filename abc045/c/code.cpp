#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    const int n = str.size() - 1;

    int64_t sum = 0;
    // 右端は常に1桁目
    // 右から2番目は50%ずつで1桁と2桁
    // 右から3番目は50%は1桁、25%ずつで2桁と3桁
    // 右から4番目は50%は1桁、25%は2桁、12.5%ずつで3桁と4桁
    for (int i = 0; i < str.size(); ++i)
    {
        int64_t scale = 1;
        for (int j = 0; j < i; ++j)
        {
            sum += scale * (str[str.size() - 1 - i] - '0') * (1 << (n - j - 1));
            scale *= 10;
        }
        sum += scale * (str[str.size() - 1 - i] - '0') * (1 << (n - (i - 1) - 1));
    }
    std::cout << sum << std::endl;
    return 0;
}
