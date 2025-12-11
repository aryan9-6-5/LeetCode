class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrices=INT_MAX;
        int maxProfit=0;
        for(int p:prices){
            minPrices=min(minPrices,p);
            maxProfit=max(maxProfit,p-minPrices);
        }
        return maxProfit;
    }
};
