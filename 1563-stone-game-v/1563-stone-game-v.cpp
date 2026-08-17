class Solution {
public:
    int rec(int l, int r, vector<int>& arr,vector<vector<int>>&dp, vector<int>& prefix) {
        if (l == r)
            return dp[l][r]=0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans = 0;
        for (int mid = l; mid < r; mid++) {
            int leftSum = prefix[mid + 1] - prefix[l];
            int rightSum = prefix[r + 1] - prefix[mid + 1];

            if (leftSum < rightSum) {
                ans = max(ans,leftSum + rec(l, mid, arr, dp,prefix));
            }
            else if (rightSum < leftSum) {
                ans = max(ans,rightSum + rec(mid + 1, r, arr,dp,prefix));
            }
            else {
                ans = max(ans,leftSum + max(rec(l, mid, arr,dp,prefix),rec(mid + 1, r, arr,dp,prefix)));
            }
        }

        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& arr) {
        	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(n,-1));
    vector<int> prefix(n+1);
    int tsum=0;
        prefix[0]=0;
    for(int i=0;i<n;i++){
        tsum+=arr[i];
        prefix[i+1]=tsum;

    }
	return rec(0,arr.size()-1,arr,dp,prefix);
    }
};