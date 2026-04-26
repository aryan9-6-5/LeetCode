class Solution {
public:
    vector<int> findValidElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0), sans(n,0);
        for(int i=1;i<n;i++){
            ans[i]=max(ans[i-1],arr[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            sans[i]=max(sans[i+1],arr[i+1]);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(arr[i]>ans[i] || arr[i]>sans[i])res.push_back(arr[i]);
        }
        return res;
    }
};
