class Solution {
public:
    int lengthOfLastWord(string s) {
        int start=s.length()-1;
        while(s[start]==' ')start--;
        if(start==-1)return 0;
        int end=start;
        while(end!=-1 && s[end]!=' ')end--;
        if(end==-1)return start+1;
        return start-end;
    }
};