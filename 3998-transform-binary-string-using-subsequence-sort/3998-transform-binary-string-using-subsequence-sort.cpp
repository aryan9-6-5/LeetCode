class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=s.length();
        int target=0;
        for(char ch:s){
            if(ch=='0')target++;
        }
        vector<int>positions;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                positions.push_back(i);
            }
        }
        vector<bool>ans;
        ans.reserve(strs.size());
        for( const string& pattern: strs){
            int cz=0;
            int wc=0;
            for(char ch: pattern){
                if(ch=='0')cz++;
                else if(ch=='?')wc++;
            }
            if(cz>target|| cz+wc<target){
                ans.push_back(false);
                continue;
            }
            int req=target-cz;
            vector<int>pzp;
            pzp.reserve(target);
            for(int i=0;i<n;i++){
                if(pattern[i]=='0'){
                    pzp.push_back(i);
                }
                else if(pattern[i]=='?'){
                    if(req>0){
                        pzp.push_back(i);
                        req--;
                    }
                }
            }
            bool possible=true;
            if(pzp.size()!=target)possible=false;
            else{
                for(int i=0;i<target;i++){
                    if(pzp[i]>positions[i]){
                        possible=false;
                        break;
                    }
                }
            }
            ans.push_back(possible);
        }
        return ans;
    }
};