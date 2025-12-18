class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int si=0;
        int gr=0;
        int maxlen=s.size();
        while(si<maxlen && gr<g.size()){
            if(s[si]>=g[gr] ){
                count++;
                gr++;
                si++;
            }
            else{
                si++;
            }
        }
        return count;
    }
};
