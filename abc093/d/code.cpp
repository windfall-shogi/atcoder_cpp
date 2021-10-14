#include <iostream>
#include <vector>

int64_t binary_search(const int64_t a, const int64_t b)
{
    int64_t left = a, right = b;
    const int64_t s = a * b;
    while (right - left > 1)
    {
        const int64_t middle = (left + right) / 2;
        if (middle * middle < s)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }
    return left;
}

int64_t solve(const int64_t a, const int64_t b)
{
    if (a == b)
    {
        return 2 * a - 2;
    }
    else if (a + 1 == b)
    {
        return 2 * a - 2;
    }
    else
    {
        // c^2 < ab, a \neq c, b \neq bを満たすcがある
        // a < c < b
        const int64_t c = binary_search(a, b);
        if (c * (c + 1) >= a * b)
        {
            // c位を取ってしまうともう1回もc位以内の必要がある
            // 2回ともc位が最も人数が増える
            return 2 * c - 2;
        }
        else
        {
            return 2 * c - 1;
        }
    }
}

int main()
{
    int q;
    std::cin >> q;
    std::vector<int64_t> as(q), bs(q);
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        if (a < b)
        {
            as[i] = a;
            bs[i] = b;
        }
        else
        {
            as[i] = b;
            bs[i] = a;
        }
    }

    for (int i = 0; i < q; ++i)
    {
        std::cout << solve(as[i], bs[i]) << std::endl;
    }
    return 0;
}
