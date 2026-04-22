class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int s=1,e=1,sp=INT_MIN,mp=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s*=nums[i];
            e*=nums[n-i-1];
            sp=max(sp,s);
            mp=max(mp,e);
            if(s==0) s=1;
            if(e==0) e=1;
        }
        return max(sp,mp);
    }
};
