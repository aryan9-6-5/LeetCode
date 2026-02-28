class Solution {
public:
    int sumOfNumbers(int l, int r, int k) {
        int a=k;
        long long m=1000000007;
        auto p=[&](long long b,long long e){
            long long res=1;
            b%=m;
            while(e>0){
                if(e&1) res=(res*b)%m;
                b=(b*b)%m;
                e>>=1;
            }
            return res;
        };
        long long md=r-l+1;
        long long d=(1LL * l+r)*md/2;
        long long pm=p(md,k-1);
        long long p10=p(10,k);
        long long s10=(p10-1+m)%m*111111112LL%m;
        long long ans=(d*pm)%m;
        return (ans*s10)%m;
        
    }
};
