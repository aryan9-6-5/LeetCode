class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int cur=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]==cur)return true;
            cur=arr[i];
        }
        return false;
    }
};
