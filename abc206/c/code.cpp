#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> table;
    for (int i = 0; i < n; ++i)
    {
        int a;
        std::cin >> a;
        table[a] += 1;
    }

    std::vector<int> counts;
    for (const auto e : table)
    {
        counts.emplace_back(e.second);
    }

    int64_t total = 0;
    int consumed = 0;
    for (const int c : counts)
    {
        const int k = n - consumed - c;
        total += static_cast<int64_t>(c) * k;
        consumed += c;
    }

    std::cout << total << std::endl;
    return 0;
}
