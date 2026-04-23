class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxprofit=0;
        for(int i:prices){
            int profit=i-mini;
            maxprofit=max(maxprofit,profit);
            mini=min(i,mini);
        }
        return maxprofit;
    }
};
