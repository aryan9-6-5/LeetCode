class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>original=arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>map;
        int rank=0;
        vector<int>ans;
        int prev=INT_MIN;
        for(auto x: arr){
            if(prev!=x){
                rank++;
                prev=x;
            } 
            map[x]=rank;
        }
        for(auto x: original){
            ans.push_back(map[x]);
        }
        return ans;

    }
};
