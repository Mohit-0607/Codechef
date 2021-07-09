def findpower(base,power):
    mod = 10**9+7
    res = 1
    while power!=0:
        if power%2==0:
            base = ((base%mod)*(base%mod))%mod
            power = power//2
        else:
            res = ((res%mod)*(base%mod))%mod
            power = power-1
    return res


def findshefola(num):
    palin = num
    num = num//10
    while num>0:
        palin = palin*10+num%10
        num = num//10
    return palin


arr = [0]*(10**5+1)
arrsm = [0]*(10**5+1)
for i in range(1,10**5+1):
    arr[i] = findshefola(i)
    arrsm[i] = arrsm[i-1] + arr[i]

for _ in range(int(input())):
    l,r = map(int,input().split())
    power = arrsm[r]-arrsm[l]
    print(findpower(arr[l],power))
