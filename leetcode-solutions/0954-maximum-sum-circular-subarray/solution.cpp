class Solution {
public:
    int kadanes(vector<int>& nums){
        int cs=0,ms=INT_MIN;
        for(int i: nums){
            cs+=i;
            ms=max(ms,cs);
            if(cs<0)cs=0;
        }
        return ms;
    }
    int skadanes(vector<int>& nums){
        int cs=0,ms=INT_MAX;
        for(int i: nums){
            cs+=i;
            ms=min(ms,cs);
            if(cs>0)cs=0;
        }
        return ms;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        for(int i:nums) sum+=i;
        int kad=kadanes(nums);
        int skad=skadanes(nums);
        if(kad<0) return kad;
        return max(kad,sum-skad);
    }
};
