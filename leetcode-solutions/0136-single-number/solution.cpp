class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sol=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sol^=nums.at(i);
        }
        return sol;
    }
};
