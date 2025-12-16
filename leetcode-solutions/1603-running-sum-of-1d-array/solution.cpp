class Solution {
public:
    vector<int> runningSum(vector<int>& arr) {
        vector<int>ans;
        int sum=0;
        for(int x:arr){
            sum+=x;
            ans.push_back(sum);
        }
        return ans;
    }
};
