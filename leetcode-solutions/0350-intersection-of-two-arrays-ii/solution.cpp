class Solution {
public:
    vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int,int> store;
        for(int i:arr1){
            store[i]++;
        }
        for(int i: arr2){
            if(store[i]>0){
                ans.push_back(i);
                store[i]--;
            }
        }
        return ans;
    }
};
