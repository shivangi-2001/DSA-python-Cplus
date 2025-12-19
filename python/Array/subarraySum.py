def subarray(nums, k):
    mp = {}
    mp[0]=1
    prefix=0
    count=0
    for num in nums:
        prefix+=num
        if(mp.get(prefix-k)):
            count += mp[prefix-k]
            
        mp[prefix]=mp.get(prefix, 0)+1
        
    return count

ans = subarray([10,2,-2,-20,10], -10)
print(ans)
    