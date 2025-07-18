class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0,count=0;
        for(int n:nums){
            if (n==1){
                count=count+1;
            }
            else{
                count=0;
            }
            max=(max>count)?max:count;
        }
        return max;
    }
};
