class Solution {
public:
    int fib(int n) {
        vector<int> fibo(n+1,-1);
        return solve(fibo,n);
    }
    int solve(vector<int>& fibo, int n){
        if(n<=0 || n==1) return n;
        if(fibo[n]!=-1) return fibo[n];
        return fibo[n]=solve(fibo,n-1)+solve(fibo,n-2);
    }
};
