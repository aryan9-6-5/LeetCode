class Solution {
public:
    int maxProduct(int n) {
        int prod=1;
        int first=-1,second=-1;
        int flag=0;
        while(n>0){
            int rem=n%10;
            if(rem >first){
                second=first;
                first=rem;
            }
            else if(rem>second){
                second=rem;
            }
            n=n/10;
        }
        return first*second;
    }
};
