# revese integer

def reverse(x):
    INT_MAX =  pow(2, 31)
    INT_MIN =  pow(-2, 31)
    ans = 0
    while(x!=0):
        digit = x/10
        if(ans > INT_MAX/10): return 0
        if(ans < INT_MIN /10): return 0
        ans = ans*10+digit
        x /= 10

    return ans

res = reverse(121)
print(res)