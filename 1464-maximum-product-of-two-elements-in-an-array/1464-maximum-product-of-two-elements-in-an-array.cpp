class Solution {
public:
    int maxProduct(vector<int>& nums) {
        pair<int,int>first,second;// value,index
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(x>first.first){
                second.first=first.first;
                second.second=first.second;
                first.first=x;
                first.second=i;
            }
            else if(x>second.first){
                second.first=x;
                second.second=i;
            }
        }
        return (nums[first.second]-1)*(nums[second.second]-1);
    }
};