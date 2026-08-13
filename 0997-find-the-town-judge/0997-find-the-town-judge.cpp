class Solution {
public:
    int findJudge(int n, vector<vector<int>>& arr) {
        if(n==1)return 1;
        vector<int> hash(n+1);
        for(auto& a: arr){
            hash[a[1]]++;   
            hash[a[0]]--;
        }
        for(int x=1;x<=n;x++){
            if(hash[x] == n-1)return x;
        }
        return -1;
    }
};