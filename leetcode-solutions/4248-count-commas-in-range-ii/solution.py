class Solution:
    def countCommas(self, n: int) -> int:
        a=0
        k=1000
        while k<=n:
            a+=(n-k+1)
            k*=1000
        return a
        
