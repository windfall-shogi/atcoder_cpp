#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    std::vector<std::pair<char, int>> run_length;
    char c = s[0];
    int count = 0;
    for (const auto d : s)
    {
        if (d != c)
        {
            run_length.emplace_back(c, count);

            c = d;
            count = 1;
        }
        else
        {
            ++count;
        }
    }
    run_length.emplace_back(c, count);

    int max_size = 0;
    int current_size = 0;
    int current_k = 0;
    size_t l = 0;
    for (size_t r = 0; r < run_length.size(); ++r)
    {
        current_size += run_length[r].second;
        if (run_length[r].first == '0')
        {
            ++current_k;
        }

        while (current_k > k)
        {
            current_size -= run_length[l].second;
            if (run_length[l].first == '0')
            {
                --current_k;
            }
            ++l;
        }

        max_size = std::max(max_size, current_size);
    }

    std::cout << max_size << std::endl;

    return 0;
}
