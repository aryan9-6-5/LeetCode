class Solution {
public:
    int rec(vector<int>& nums,int index,vector<int>& dp){
        if(index==0)return nums[index];
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        int pick=nums[index]+rec(nums,index-2,dp);
        int nopick=0+rec(nums,index-1,dp);
        return dp[index]= max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int>dp(nums.size(),-1);
        return rec(nums, nums.size()-1, dp);
    }
};