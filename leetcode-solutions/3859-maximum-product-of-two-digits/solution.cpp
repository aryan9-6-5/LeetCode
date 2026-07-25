class Solution {
public:
    int maxProduct(int n) {
        int prod=1;
        int count=0;
        int first=-1,second=-1;
        int flag=0;
        while(n>0){
            int rem=n%10;
            if (count<2){
                if(first==-1)first=rem;
                else if(second==-1)second=rem;
                count++;
            }
            else{
                if(first>second){
                    swap(first,second);
                }
                if(rem > first){
                    first=rem;
                }
                else if(rem >second){
                    second=rem;
                }
            }
            n=n/10;
        }
        return first*second;
    }
};
