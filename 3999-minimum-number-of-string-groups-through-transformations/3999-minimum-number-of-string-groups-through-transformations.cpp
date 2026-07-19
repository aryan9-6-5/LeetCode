class Solution {
public:
    string getmin(const string& s){
        int n=s.length();
        if(n==0)return s;
        string ss=s+s;
        int len=ss.length();
        vector<int> f(len,-1);
        int k=0;
        for(int j=1;j<len;j++){
            char sj=ss[j];
            int i=f[j-k-1];
            while(i!=-1 && sj!=ss[k+i+1]){
                if(sj<ss[k+i+1])k=j-i-1;
                i=f[i];
            }
            if(sj!=ss[k+i+1]){
                if(sj<ss[k])k=j;
                f[j-k]=-1;
            }
            else{
                f[j-k]=i+1;
            }
        }
        k=k%n;
        return s.substr(k)+s.substr(0,k);
    }
    int minimumGroups(vector<string>& words) {
        unordered_set<string> unique;
        for(const string& word: words){
            string even="";
            string odd="";
            int len=word.length();
            even.reserve(len/2+1);
            odd.reserve(len/2+1);
            for(int i=0;i<len;i++){
                if(i%2==0) even+=word[i];
                else odd+=word[i];
            }
            string ceven=getmin(even);
            string codd=getmin(odd);
            string crep=ceven+"#"+codd;
            unique.insert(crep);
        }
        return unique.size();
    }
};