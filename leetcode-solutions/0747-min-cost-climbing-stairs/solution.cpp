class Solution {
public:
        int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(minCost(cost,0,dp),minCost(cost,1,dp));
    }
    int minCost(vector<int>& cost, int idx,vector<int>& dp){
        int n=cost.size();
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=cost[idx]+min(minCost(cost,idx+1,dp),minCost(cost,idx+2,dp));
    }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n=cost.size();
    //     vector<int> dp(n,-1);
    //     dp[0]=cost[0];
    //     dp[1]=cost[1];
    //     for(int i=2;i<n;i++){
    //         dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    //     }
    //     return min(dp[n-1],dp[n-2]);
    // }
};
