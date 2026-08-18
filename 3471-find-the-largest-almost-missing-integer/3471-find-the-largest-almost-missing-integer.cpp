class Solution {
public:
    int largestInteger(vector<int>& arr, int k) {
        int left=0,right=0;
        int n=arr.size();
        unordered_map<int,int>hash;
        for(int i=0;i<=n-k;i++){
            unordered_set<int>seen;
            for(int j=i;j<i+k;j++){
                seen.insert(arr[j]);
            }
            for( int x: seen) hash[x]++;
        }
        int ans=-1;
        for(auto x: hash){
            if(x.second==1)ans=max(ans, x.first);
        }
        return ans;        
    }
};