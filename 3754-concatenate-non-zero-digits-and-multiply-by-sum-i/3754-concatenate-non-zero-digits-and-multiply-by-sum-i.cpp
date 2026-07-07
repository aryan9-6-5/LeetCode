class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum1=0;
        long long prod=0;
        long long rev=0;
        while(n>0){
            int cur=n%10;
            if(cur!=0){
                sum1+=cur;
                if(rev==0)rev=cur;
                else rev=rev*10+cur;
            }
            n/=10;
        }
        while(rev>0){
            int cur=rev%10;
            if(prod==0) prod=cur;
            else prod=prod*10+cur;
            rev/=10;
        }
        return prod*sum1;
    }
};