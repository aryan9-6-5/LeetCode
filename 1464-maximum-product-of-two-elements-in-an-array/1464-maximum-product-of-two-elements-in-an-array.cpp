class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first=INT_MIN,second=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(x>first){
                second=first;
                first=x;
            }
            else if(x>second){
                second=x;
            }
        }
        return (first-1)*(second-1);
    }
};