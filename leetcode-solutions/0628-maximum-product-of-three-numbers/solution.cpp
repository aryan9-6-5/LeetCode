class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int prod=1;
        int first=INT_MIN,second=INT_MIN,third=INT_MIN,min1=INT_MAX,min2=INT_MAX;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            int rem=nums[i];
            if(first<rem){
                third=second;
                second=first;
                first=rem;
            }
            else if(second<rem){
                third=second;
                second=rem;
            }
            else if (third<rem){
                third=rem;
            }
            if(rem<min1){
                min2=min1;
                min1=rem;
            }
            else if(rem<min2){
                min2=rem;
            }
        }
        return max(first*second*third,first*min1*min2);
    }
};
