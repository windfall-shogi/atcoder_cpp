#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    // 負の二項分布の期待値
    // 成功確率p, k回成功するまでの全体の試行回数x
    // E[x] = k/p

    // 1回あたりの試行時間
    const int t = 1900 * m + 100 * (n - m);
    // 成功確率の逆数
    const int q = 1 << m;

    std::cout << q * t << std::endl;
    return 0;
}
