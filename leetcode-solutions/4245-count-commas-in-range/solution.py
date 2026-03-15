class Solution:
    def countCommas(self, n: int) -> int:
        ans=0
        for i in range(n+1):
            ans+=(len(str(i))-1)//3
        return ans
