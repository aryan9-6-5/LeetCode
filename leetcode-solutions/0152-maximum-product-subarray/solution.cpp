class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,cp=1,suffix=1,sol=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix=nums[i]*prefix;
            suffix=nums[n-i-1]*suffix;
            sol=max(sol,max(prefix,suffix));
        }
        return sol;
    }
};
