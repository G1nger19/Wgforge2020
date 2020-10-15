t , k = map(int,input().split())
info = []


for _ in range(t) :
    mn = list(map(int,input().split()))
    info.append(mn)


for el in info :
    el.sort()
    if (el[1] - el[0] + el[0] // (k + 1) * (k != 1)) % 2 == 1 or el[0] % (k + 1) == 0 :
        print('+')
    else:
        print('-')
