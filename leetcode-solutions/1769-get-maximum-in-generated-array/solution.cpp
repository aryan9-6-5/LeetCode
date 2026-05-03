class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0 || n==1)return n;

        vector<int>ans(n+1);
        int maxi=INT_MIN;
        ans[0]=0;
        ans[1]=1;
        int index=1;
        for(int i=2;i<=n;i++){
            if(i%2==0)ans[i]=ans[i/2];
            else {
                ans[i]=ans[index]+ans[index+1];
                index++;
            }
            maxi=max(ans[i],maxi);
        }
        return maxi;
    }
};
