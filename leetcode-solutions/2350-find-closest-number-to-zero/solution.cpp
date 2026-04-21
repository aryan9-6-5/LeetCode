class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int smallest=nums[0];
        for(int i:nums){
            if(abs(i)<abs(smallest)){
                smallest=i;
            }
            else if(abs(i)==abs(smallest)){
                smallest=max(i,smallest);
            }
        }
        return smallest;
    }
};
