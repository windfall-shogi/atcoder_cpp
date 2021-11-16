#include <iostream>
#include <vector>

std::vector<int64_t> compute_size(const int n)
{
    std::vector<int64_t> sizes(n + 1);
    sizes[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        sizes[i] = 3 + sizes[i - 1] * 2;
    }
    return sizes;
}

std::vector<int64_t> compute_patty(const int n)
{
    std::vector<int64_t> patties(n + 1);
    patties[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        patties[i] = 1 + patties[i - 1] * 2;
    }
    return patties;
}

int64_t solve(const std::vector<int64_t> &sizes, const std::vector<int64_t> &patties,
              const int level, const int64_t x)
{
    if (x <= 0)
    {
        return 0;
    }
    if (x == sizes[level])
    {
        return patties[level];
    }

    const auto half = sizes[level] / 2;
    int64_t ans = 0;
    if (x > half)
    {
        ans += solve(sizes, patties, level - 1, half - 1);
        ans += 1;
        ans += solve(sizes, patties, level - 1, x - half - 1);
    }
    else
    {
        ans += solve(sizes, patties, level - 1, x - 1);
    }

    return ans;
}

int main()
{
    int n;
    int64_t x;
    std::cin >> n >> x;

    const auto sizes = compute_size(n);
    const auto patties = compute_patty(n);

    const int64_t ans = solve(sizes, patties, n, x);
    std::cout << ans << std::endl;

    return 0;
}
