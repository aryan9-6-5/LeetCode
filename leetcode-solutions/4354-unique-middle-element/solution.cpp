class Solution {
public:
    bool isMiddleElementUnique(vector<int>& a) {
        int b=a.size();
        if(b==0)return false;
        int c=b/2;
        int d= a[c];
        int e=0;
        for(int i=0;i<b;i++){
            if(a[i]==d)e++;
        }
        return e==1;
    }
};
