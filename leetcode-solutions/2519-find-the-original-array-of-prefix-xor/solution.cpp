class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        if(pref.size()==1)return pref;
        vector<int>arr(pref.size());
        arr[0]=pref[0];
        for(int i=1;i<pref.size();i++){
            arr[i]=pref[i]^pref[i-1];
        }
        return arr;
    }
};
