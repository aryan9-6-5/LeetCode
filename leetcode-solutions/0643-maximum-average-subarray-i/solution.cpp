class Solution {
public:
    double findMaxAverage(vector<int>& arr, int k) {
        int n=arr.size();
        if(n<k) return 0;
        double s=0;
        for(int i=0;i<k;i++){
            s+=arr[i];
        }
        double favg=s/k;
        double maxsum=s;
        double sum=s;
        for(int i=k ;i<n ;i++){
            sum+=arr[i]-arr[i-k];
            maxsum=max(sum,maxsum);
        }
        double maxavg=maxsum/k;
        if(maxavg<favg) return favg;
        return maxavg;
    }
};
