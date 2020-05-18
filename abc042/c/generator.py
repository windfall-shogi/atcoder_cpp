#!/usr/bin/env python3

import random

def main():
    n = random.randint(1, 10000 - 1)
    k = random.randint(1, 10 - 1)
    print('{} {}'.format(n, k))

    d = random.sample(range(10), k)
    while k == 9 and 0 not in d:
        d = random.sample(range(10), k)
    d.sort()
    print(' '.join([str(v) for v in d]))


if __name__ == '__main__':
    main()

