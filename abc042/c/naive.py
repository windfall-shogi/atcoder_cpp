#!/usr/bin/env python3

def main():
    n, k =  map(int, input().split())
    ng_set = set(map(int, input().split()))

    while True:
        tmp = str(n)
        if all(int(t) not in ng_set for t in tmp):
            print(n)
            break
        n += 1


if __name__ == '__main__':
    main()
