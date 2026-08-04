class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(mn > nums[i])    mn = nums[i];
            if(mx < nums[i])    mx = nums[i];
        }
        vector<int> arr(mx+1,0);
        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }
        vector<int> res;
        for(int i = mn; i < mx+1; i++){
            if(arr[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};