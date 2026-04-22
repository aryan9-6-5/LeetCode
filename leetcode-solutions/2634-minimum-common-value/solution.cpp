class Solution {
public:
    int getCommon(vector<int>& arr1, vector<int>& arr2) {
        int res=INT_MAX;
        unordered_set<int> store;
        int i=0;
        int j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]==arr2[j] && arr1[i]<res) return arr1[i];
            if(arr1[i]<arr2[j])i++;
            else if (arr2[j]<arr1[i])j++;
        }
        return -1;
    }
};
