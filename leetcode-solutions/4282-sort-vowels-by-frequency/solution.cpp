class Solution {
public:
string sortVowels(string s) {
    int n = s.size();
    string vs = "aeiou";
    
    map<char,int> fr;
    map<char,int> fi;
    
    for(int i=0;i<n;i++){
        if(vs.find(s[i])!=string::npos){
            fr[s[i]]++;
            if(!fi.count(s[i]))
                fi[s[i]]=i;
        }
    }
    
    vector<char> vc;
    for(auto p:fr)
        vc.push_back(p.first);
    
    sort(vc.begin(),vc.end(),[&](char a,char b){
        if(fr[a]!=fr[b]) return fr[a]>fr[b];
        return fi[a]<fi[b];
    });
    
    string pl="";
    for(char c:vc)
        for(int i=0;i<fr[c];i++)
            pl+=c;
    
    int j=0;
    for(int i=0;i<n;i++)
        if(vs.find(s[i])!=string::npos)
            s[i]=pl[j++];
    
    return s;
}
};
