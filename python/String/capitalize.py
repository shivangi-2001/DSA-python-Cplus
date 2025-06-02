str = "hello world"

ans = ""
for i in range(0, len(str)):
    if(str[i]== ' '):
        print(ans, end="\n")
        ans = ""

    ans+=str[i]
