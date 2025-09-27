class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0;
        int neg=1;
        int len=nums.size();
        vector<int> sol(len);
        for(int i=0;i<len;i++){
            if(nums[i]>0){
                sol[pos]=nums[i];
                pos+=2;
            }
            else{
                sol[neg]=nums[i];
                neg+=2;
            }
        }
        return sol;
    }
};
