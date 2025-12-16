class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int maxsum=0;
        for(int x:gain){
            sum+=x;
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};
