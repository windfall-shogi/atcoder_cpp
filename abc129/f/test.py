#! /usr/bin/env python3
# -*- coding: utf-8 -*-
"""
どこで間違えているかわからないので、確認用
"""

import math


def main():
    l = 4
    a = 1010000000000014
    b = 1000000000000007
    m = 998244353

    print(solve(l, a, b, m))

    print(f(l, 10 ** get_digits(a), m) * a % m)


def get_digits(x):
    a = math.floor(math.log10(x)) + 1
    return int(a)


def solve(l, a, b, m):
    ans = 0
    for i in range(l):
        x = a + i * b
        k = get_digits(x)
        ans *= 10 ** k % m
        ans %= m
        ans += x % m
        ans %= m
    return ans


def pow_(x, p, m):
    a = 1
    for _ in range(p):
        a *= x % m
        a %= m
    return a


def f(n, base, m):
    if n == 0:
        return 0
    elif n % 2 == 1:
        tmp = f(n - 1, base, m)
        return (tmp * base + 1) % m
    else:
        tmp = f(n // 2, base, m)
        return (tmp * pow_(base, n // 2, m) + tmp) % m


if __name__ == '__main__':
    main()
