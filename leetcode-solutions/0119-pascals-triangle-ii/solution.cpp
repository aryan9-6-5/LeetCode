class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> a;
        long long ans=1;
        for(int i=0;i<=n;i++){
            a.push_back(ans);
            ans=ans*(n-i)/(i+1);
        }
        return a;
    }
};
