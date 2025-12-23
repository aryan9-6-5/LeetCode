class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>hash;
        vector<int> ans;
        int minc= n/3 +1;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(auto& it:hash){
            if(it.second>=minc) ans.push_back(it.first);
            if(ans.size()==2) break;
        }
        return ans;
    }
};
