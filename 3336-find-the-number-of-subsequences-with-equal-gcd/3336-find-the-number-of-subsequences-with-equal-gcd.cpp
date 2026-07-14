class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        static const int MOD=1e9+7;
        vector<vector<int>> dp(201,vector<int>(201,0));
        dp[0][0]=1;
        for(int x: nums){
            vector<vector<int>>ndp=dp;
            for(int g1=0;g1<=200;g1++){
                for(int g2=0;g2<=200;g2++){
                    if(dp[g1][g2]==0) continue;
                    int ng1,ng2;
                    if(g1==0)ng1=x;
                    else ng1=gcd(g1,x);
                    ndp[ng1][g2]=(ndp[ng1][g2]+dp[g1][g2])% MOD;
                    if(g2==0)ng2=x;
                    else ng2=gcd(g2,x);
                    ndp[g1][ng2]=(ndp[g1][ng2]+dp[g1][g2])% MOD;

                }
            }
            dp=move(ndp);
        }
        long long ans=0;
        for(int x=1;x<=200;x++){
            ans=(ans+dp[x][x])%MOD;
        }
        return ans;
    }
};