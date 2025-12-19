class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last=nums.size();
        int cur=0;
        int maxreach=0;
        for(int i=0;i<last;i++){
            if(i>maxreach) return false;
            maxreach=max(maxreach,i+nums[i]);
            if(maxreach==last-1) return true;
        }
        return true;
    }
};
