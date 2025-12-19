def prefixSum(nums, l, r):
    prefix = [0]*len(nums)
    prefix[0]=nums[0]
    for i in range(1, len(nums)):
        prefix[i]=prefix[i-1]+nums[i]
        
    if l==0:
        return prefix[r]
    else:
        return prefix[r]-prefix[l-1]
    
ans = prefixSum([10,20,40,10,-10], 2, 4)
print(ans)