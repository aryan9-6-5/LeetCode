class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int start=0;
        int end=1;
        while(end<s.length()){
            if(abs((s[start]-'0')-(s[end]-'0'))>2)return false;
            start++;
            end++;
        }
        return true;
    }
};
