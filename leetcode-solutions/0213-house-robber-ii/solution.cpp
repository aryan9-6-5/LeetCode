class Solution {
public:
    int rec(vector<int>& nums){
        int n = nums.size();
        int first = 0;       
        int second = nums[0];
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + first;
            int nopick = second;
            int curr = max(pick, nopick);
            first = second;
            second = curr;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1;
        vector<int>temp2;
        temp2.push_back(nums[0]);
        for(int i=1;i<n-1;i++){
            temp1.push_back(nums[i]);
            temp2.push_back(nums[i]);
        }
        temp1.push_back(nums[n-1]);
        int ans1=rec(temp1);
        int ans2=rec(temp2);
        return max(ans1,ans2);
    }
};
