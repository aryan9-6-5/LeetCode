class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> ans;
        unordered_set<int> store;
        int len1=arr1.size();
        int len2=arr2.size();
        if(len1>len2){
            for(int i:arr1){
                store.insert(i);
            }
            for(int i:arr2){
                if(store.contains(i)) ans.insert(i);
            }
        }
        else{
            for(int i:arr2){
                store.insert(i);
            }
            for(int i:arr1){
                if(store.contains(i)) ans.insert(i);
            }
        }
        return vector<int>(ans.begin(),ans.end());   
    }
};
