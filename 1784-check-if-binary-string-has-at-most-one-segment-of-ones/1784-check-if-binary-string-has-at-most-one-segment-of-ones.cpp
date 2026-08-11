class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='0' && i+1<n && s[i+1]=='1')return false;
        }
        return true;
    }
};