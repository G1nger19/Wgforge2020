def solution():
    count = 0
    n , k = map(int , input().split())
    for i in range(2, n + 1):
        if k % i == 0 and k <= n * i :
            count += 1
    if k <= n:
        count += 1
    print(count)
solution()