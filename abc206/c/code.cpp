#include <iostream>
#include <unordered_map>

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

    int64_t total = 0;
    int consumed = 0;
    for (const auto &e : table)
    {
        const int c = e.second;
        const int k = n - consumed - c;
        total += static_cast<int64_t>(c) * k;
        consumed += c;
    }

    std::cout << total << std::endl;
    return 0;
}
