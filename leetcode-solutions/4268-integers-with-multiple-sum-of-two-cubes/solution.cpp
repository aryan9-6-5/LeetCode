class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int> res;
        unordered_map<long long ,int> hash;
        int l=cbrt(n);
        for(int a =1;a<=l;++a){
            long long ac=1LL*a*a*a;
            for(int b=a;b<=l;++b){
                long long s=ac+(1LL *b*b*b);
                if(s>n) break;
                hash[s]++;
            }
        }
        for(auto& [a, b]:hash) if(b>=2)res.push_back((int)a);
        sort(res.begin(),res.end());
        return res;
    }
};
