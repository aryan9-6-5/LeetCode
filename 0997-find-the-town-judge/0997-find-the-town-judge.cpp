class Solution {
public:
    int findJudge(int n, vector<vector<int>>& arr) {
        if(n==1)return 1;
        map<int,int> hash;
        for(auto& a: arr){
            hash[a[1]]++;   
            hash[a[0]]--;
        }
        for(auto x: hash){
            if(x.second==n-1)return x.first;
        }
        return -1;
    }
};