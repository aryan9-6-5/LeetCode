class Solution {
public:
    int findCenter(vector<vector<int>>& arr) {
        int n=arr.size()+1;
        if( n==1)return 1;
        vector<int>indegree(n+1);
        for( auto& a: arr){
            indegree[a[1]]++;
            indegree[a[0]]++;
        }
        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1)return i;
        }
        return -1;
    }
};