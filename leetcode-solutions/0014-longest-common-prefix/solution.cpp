class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans="";
        int n=s.size();
        int len=s[0].size();
        sort(s.begin(),s.end());
        int i=0;
        for(int i=0;i<len;i++){
            if(s[0][i]!=s[n-1][i]) return ans;
            ans+=s[0][i];
        }
        return ans;
    }
};
