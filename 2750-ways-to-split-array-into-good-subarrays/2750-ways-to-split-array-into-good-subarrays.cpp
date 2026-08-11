class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& arr) {
        vector<int>ones;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1)ones.push_back(i);
        }
        if(ones.empty())return 0;
        long long ans=1;
        long long mod=1e9+7;
        for(int i=0;i<ones.size()-1;i++){
            long long gap=ones[i+1]-ones[i];
            ans=(ans*gap)%mod;
        }
        return (int) ans;
    }
};