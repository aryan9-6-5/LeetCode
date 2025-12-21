class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxsum=0;
        for(int i=0;i<n;i+=2){
            maxsum+=nums[i];
        }
        return maxsum;
    }
};
