class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<>());
        int count=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(count==2){
                count=0;
            }
           else{
                c+=cost[i];
                count++;
           }
        }
        return c;
    }
};
