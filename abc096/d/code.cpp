#include <iostream>
#include <vector>

std::vector<int> get_prime_numbers()
{
    constexpr int MAX_SIZE = 55555;
    std::vector<bool> x(MAX_SIZE + 1, true);
    x[0] = x[1] = false;

    for (int i = 2; i * i <= MAX_SIZE; ++i)
    {
        if (!x[i])
        {
            continue;
        }

        for (int j = i * 2; j <= MAX_SIZE; j += i)
        {
            x[j] = false;
        }
    }

    std::vector<int> primes;
    primes.reserve(55);
    for (int i = 2; i <= MAX_SIZE; ++i)
    {
        if (x[i] && i % 5 == 1)
        {
            primes.emplace_back(i);
        }
    }

    return primes;
}
int main()
{
    int n;
    std::cin >> n;

    const std::vector<int> primes = get_prime_numbers();
    for (int i = 0; i < n; ++i)
    {
        std::cout << primes[i];
        if (i < n - 1)
        {
            std::cout << ' ';
        }
        else
        {
            std::cout << std::endl;
        }
    }

    return 0;
}
