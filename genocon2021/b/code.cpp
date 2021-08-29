#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>

// 残りの文字数をkeyとしたスコアのテーブル
int Scores[401][401];

enum Type
{
    MATCH,      // ペアとして消費する
    INSERTION1, // sの方に'-'を挿入する
    INSERTION2, // tの方に'-'を挿入する
    UNDEFINED   // 未定義
};

Type TypeTable[401][401];

int compute_alignment(const std::string &s, const std::string &t)
{
    if (TypeTable[s.size()][t.size()] != UNDEFINED)
    {
        return Scores[s.size()][t.size()];
    }

    if (s.empty() && t.empty())
    {
        TypeTable[0][0] = MATCH;
        Scores[0][0] = 0;
        return 0;
    }
    else if (s.empty())
    {
        // sの方に'-'を入れるしかない
        TypeTable[0][t.size()] = INSERTION1;

        const auto tmp_t = t.substr(1);
        Scores[0][t.size()] = compute_alignment(s, tmp_t) - 5;
        return Scores[0][t.size()];
    }
    else if (t.empty())
    {
        // tの方に'-'を入れるしかない
        TypeTable[s.size()][0] = INSERTION2;

        const auto tmp_s = s.substr(1);
        Scores[s.size()][0] = compute_alignment(tmp_s, t) - 5;
        return Scores[s.size()][0];
    }

    // 両方の長さが1以上
    const auto tmp_s = s.substr(1);
    const auto tmp_t = t.substr(1);

    const int score1 = compute_alignment(tmp_s, tmp_t) + (s[0] == t[0] ? 1 : -3);
    const int score2 = compute_alignment(s, tmp_t) - 5;
    const int score3 = compute_alignment(tmp_s, t) - 5;

    const std::array<int, 3> a = {score1, score2, score3};
    const std::array<Type, 3> ops = {MATCH, INSERTION1, INSERTION2};

    const auto it = std::max_element(a.begin(), a.end());
    Scores[s.size()][t.size()] = *it;
    TypeTable[s.size()][t.size()] = ops[std::distance(a.begin(), it)];

    return Scores[s.size()][t.size()];
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    for (int i = 0; i < 401; ++i)
    {
        for (int j = 0; j < 401; ++j)
        {
            Scores[i][j] = -400 * 5 * 2;
            TypeTable[i][j] = UNDEFINED;
        }
    }

    compute_alignment(s, t);

    auto size_s = s.size(), size_t = t.size();
    std::vector<char> buffer_s, buffer_t;
    buffer_s.reserve(800);
    buffer_t.reserve(800);

    while (size_s != 0 || size_t != 0)
    {
        if (TypeTable[size_s][size_t] == MATCH)
        {
            buffer_s.push_back(s[s.size() - size_s]);
            buffer_t.push_back(t[t.size() - size_t]);

            --size_s;
            --size_t;
        }
        else if (TypeTable[size_s][size_t] == INSERTION1)
        {
            buffer_s.push_back('-');
            buffer_t.push_back(t[t.size() - size_t]);

            --size_t;
        }
        else if (TypeTable[size_s][size_t] == INSERTION2)
        {
            buffer_s.push_back(s[s.size() - size_s]);
            buffer_t.push_back('-');

            --size_s;
        }
    }

    for (const auto c : buffer_s)
    {
        std::cout << c;
    }
    std::cout << std::endl;
    for (const auto c : buffer_t)
    {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
