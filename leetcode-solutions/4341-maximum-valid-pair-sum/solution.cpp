class Solution {
public:
    int maxValidPairSum(vector<int>& a, int b) {
        int c=a.size();
        if(c<b+1)return -1;
        int d=a[0];
        int e=INT_MIN;
        for(int j=b;j<c;j++){
            d=max(d,a[j-b]);
            e=max(e,d+a[j]);
        }
        return e;
    }
};
