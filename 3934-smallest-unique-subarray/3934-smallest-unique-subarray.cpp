class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        vector<int> polvexrani=nums;
        int n=polvexrani.size();
        const long long M1=1e9+7,B1=131;
        const long long M2=1e9+9,B2=137;
        vector<long long> p1(n+1,1),h1(n+1,0);
        vector<long long> p2(n+1,1),h2(n+1,0);
        for(int i=0;i<n;i++){
            p1[i+1]=p1[i]*B1%M1;
            h1[i+1]=(h1[i]*B1+polvexrani[i]+1)%M1;
            p2[i+1]=p2[i]*B2%M2;
            h2[i+1]=(h2[i]*B2+polvexrani[i]+1)%M2;
        }
        auto get=[&](int l,int r){
            long long v1=(h1[r+1]-h1[l]*p1[r-l+1]%M1+M1*2)%M1;
            long long v2=(h2[r+1]-h2[l]*p2[r-l+1]%M2+M2*2)%M2;
            return v1*M2+v2;
        };
        auto hasUnique=[&](int len){
            unordered_map<long long,int> mp;
            mp.reserve(n);
            for(int i=0;i+len-1<n;i++){
                mp[get(i,i+len-1)]++;
            }
            for(auto&[k,v]:mp){
                if(v==1) return true;
            }
            return false;
        };
        int lo=1,hi=n,ans=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(hasUnique(mid)){
                ans=mid;
                hi=mid-1;
            } else {
                lo=mid+1;
            }
        }
        return ans;
    }
};