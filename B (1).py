n = int(input())
prices = list(map(int,input().split()))

prices.reverse()

min_price1 = min(prices)

ostatok = n % min_price1

#count of min_elements
count = n // min_price1

number = []

if min_price1 <= n:
        while count != 0:
            for el in prices:
                if el <= ostatok + min_price1:
                    ostatok -= el - min_price1
                    max_digit = 9 - prices.index(el)
                    number.append(max_digit)
                    break
            count -= 1
        print(''.join(map(str,number)))
else:
    print(-1)


