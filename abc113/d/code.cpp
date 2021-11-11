#include <iostream>
#include <vector>

constexpr int64_t MOD = 1000000007;

std::vector<int> make_table()
{
    std::vector<bool> table(128);
    for (int i = 0; i < 128; ++i)
    {
        const int tmp = i & (i << 1);
        table[i] = tmp == 0;
    }

    std::vector<int> counter(8, 1);
    for (int i = 1; i < 7; ++i)
    {
        int c = 0;
        for (int j = 0; j < (1 << i); ++j)
        {
            if (table[j])
            {
                ++c;
            }
        }
        counter[i] = c;
    }

    return counter;
}

int PATTERN[8][3];

void initialize(const int w, const int x, const std::vector<int> &counter)
{
    int64_t ans = 1;
    int64_t left = 1, middle = 1, right = 1;
    // 左から来る場合
    if (x > 0)
    {
        if (x >= 2)
        {
            left *= counter[x - 2];
            left %= MOD;
        }
        if (x < w - 2)
        {
            left *= counter[w - 1 - (x + 1)];
            left %= MOD;
        }
    }
    else
    {
        left = 0;
    }
    // 上からそのまま来る
    if (x >= 2)
    {
        middle *= counter[x - 1];
        middle %= MOD;
    }
    if (x < w - 2)
    {
        middle *= counter[w - 1 - (x + 1)];
        middle %= MOD;
    }
    // 右から来る場合
    if (x <= w - 2)
    {
        if (x >= 2)
        {
            right *= counter[x - 1];
            right %= MOD;
        }
        if (x < w - 3)
        {
            right *= counter[w - 1 - (x + 2)];
            right %= MOD;
        }
    }
    else
    {
        right = 0;
    }

    PATTERN[x][0] = left;
    PATTERN[x][1] = middle;
    PATTERN[x][2] = right;
}

int main()
{
    int h, w, k;
    std::cin >> h >> w >> k;
    --k;

    const auto counter = make_table();
    for (int i = 0; i < w; ++i)
    {
        initialize(w, i, counter);
    }

    std::vector<int64_t> current(w), previous(w);
    previous[0] = 1;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            int64_t left = 0, middle = 0, right = 0;
            if (j > 0)
            {
                left = previous[j - 1] * PATTERN[j][0];
                left %= MOD;
            }
            middle = previous[j] * PATTERN[j][1];
            middle %= MOD;
            if (j < w - 1)
            {
                right = previous[j + 1] * PATTERN[j][2];
                right %= MOD;
            }
            current[j] = left + middle + right;
            current[j] %= MOD;
        }

        current.swap(previous);
    }

    std::cout << previous[k] << std::endl;

    return 0;
}
