class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0;
       int minlen=INT_MAX;
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                minlen=min(minlen,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
         if(minlen==INT_MAX){
           minlen=0;
        }
        return minlen;
        }
        
};
