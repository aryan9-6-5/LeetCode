class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& arr) {
     map<int,int>f;
        for(int v: arr) f[v]++;
        for(auto i=f.begin();i!=f.end();++i){
            for(auto j=next(i);j!=f.end();++j){
                if(i->second!=j->second){
                    return{i->first,j->first};
                }
            }
        }
        return{-1,-1};
    }
};
