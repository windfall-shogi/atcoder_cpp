#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

constexpr int32_t MOD = 1000000007;

int msb(int64_t n)
{
    int count = 0;
    while (n != 0)
    {
        ++count;
        n >>= 1;
    }
    return count;
}

int main()
{
    int64_t n;
    std::cin >> n;

    /*
        解説にもある通りu<=vである。
        v<=Nを満たす範囲で、a,bのビット列のパターンを列挙する。
        a,bは各桁について対称性があるので、
        桁ごとに両方が0、一方が1もう一方が0、両方が1の3通りの状態がある。
        これをvの制約を満たすパターンの個数を数え上げる。
        また、この時、ある桁でa,bの両方が0の場合と1の場合で同じuになるが、vは異なっている。
        よって、a,bのパターンを数え上げればよいことがわかる。

        上位から桁DPを行う。
        繰り上がりによってa+bがNを超えるかは、(a+b)>>iとN>>iの差を調べることで判定できる。
        ここで、ｉは下位からの桁数である。
        j=(N>>i)-((a+b)>>i)として、
        j==0の場合、Ｎのi桁目が0ならa,bのi桁目も両方0でないとNを超える。
        j==1の場合、下に示すようにa,bのi桁目が両方1の場合にNを超える。
            N>>i     : 11     11  or, 10    10
            (a+b)>>i : 10 -> 110      01 -> 11
                a[i] :  1              1
                b[i] :  1              1
        j>=2の場合、以下のような状態が一例として示される。
        　　　　　　　a,bが両方1でもj>=2の状態が保たれる（次では一つ下の桁を扱うのでj>=2は変わらない）
            N>>i     : 111    111  or,  110    110
            (a+b)>>i : 011 -> 101       011 -> 101
                a[i] :   1                1
                b[i] :   1                1

        dp[j]は(N>>i)-((a+b)>>i)がj(ただし、2以上は2にまとめる)であるときの場合の数である。
    */
    std::vector<int64_t> dp(3);

    const int k = msb(n);
    for (int i = k - 1; i >= 0; --i)
    {
        if (i == k - 1)
        {
            dp[0] = 1;
            dp[1] = 1;
            continue;
        }
        std::vector<int64_t> tmp(3);
        if ((n >> i) % 2)
        {
            tmp[0] = dp[0];
            tmp[1] = dp[1] + dp[0];
            tmp[2] = dp[2] * 3 + dp[1] * 2;
        }
        else
        {
            tmp[0] = dp[0] + dp[1];
            tmp[1] = dp[1];
            tmp[2] = dp[2] * 3 + dp[1];
        }
        std::transform(tmp.begin(), tmp.end(), dp.begin(), [&](const int64_t v) { return v % MOD; });
    }

    std::cout << (std::accumulate(dp.begin(), dp.end(), 0ll) % MOD) << std::endl;
    return 0;
}
