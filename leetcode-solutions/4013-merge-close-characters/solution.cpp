class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool r=true;
        while(r){
            r=false;
            int len=s.length();
            for(int i=0;i<len;++i){
                for(int j=i+1;j<=i+k && j<len ;++j){
                    if(s[i]==s[j]){
                        s.erase(j,1);
                        r=true;
                        break;
                    }
                }
                if (r) break;
            }
        }
        return s;
    }
};
