class Solution {
public:
    long long mirrorFrequency(string s) {
        unordered_map<char ,int> hash;
        for(char c :  s)hash[c]++;
        long long total=0;
        unordered_set<char> se;
        for(auto const& [a, b]:hash){
            if(se.count(a))continue;
            char m='a';
            if(isdigit(a))m=('0'+'9'-a);
            else m='a'+'z'-a;
            int c=0;
            if(hash.count(m)) c=hash[m];
            else c=0;
            total+=abs(b-c);
            se.insert(a);
            se.insert(m);
        }
        return total;
        
    }
};
