class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        int count[1001]={0};
        int n=nums.size();
        for(auto& a: nums){
            for(int i: a){
                count[i]++;
            }
        }
        for(int i=0;i<1001;i++){
            if(count[i]== n) ans.push_back(i);
        }
        return ans;
    }
};
