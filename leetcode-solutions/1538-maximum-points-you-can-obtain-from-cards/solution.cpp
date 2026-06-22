class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        long long current=0;
        int n=arr.size();
        for(int i=0;i<k;i++) {
            current+=arr[i];
        }
        long long maxSum=current,right=n-1;
        for(int i=k-1;i>=0;i--){
            current-=arr[i];
            current+=arr[right];
            maxSum=max(maxSum,current);
            right--;
        }
        return maxSum;
    }
};
