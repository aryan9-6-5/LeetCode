class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        int n = nums.size();
        for(int x:nums){
            if(x<mn)    mn = x;
            if(x >mx)    mx = x;
        }
        vector<int> arr(mx-mn+1,0);
        for(int x:nums){
            arr[x-mn]++;
        }
        vector<int> res;
        for(int i = 0; i <mx-mn+1; i++){
            if(arr[i] == 0){
                res.push_back(i+mn);
            }
        }
        return res;
    }
};