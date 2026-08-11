class Solution {
public:
    int req(int speed, vector<int>& piles){
        long long hours=0;
        for(int x: piles){
            hours+=(x+speed-1)/speed;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=INT_MIN;
        for(int x: piles){
            right=max(right, x);
        }
        while(left<right){
            int mid=left+(right-left)/2;
            if(req(mid,piles)<=h){
                right=mid;
            }
            else left=mid+1;
        }
        return left;
    }
};