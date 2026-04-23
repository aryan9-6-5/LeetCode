class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            long long smallest=arr[i];
            long long largest=arr[i];
            for(int j=i+1;j<n;j++){
                smallest = min((long long)arr[j], smallest);
                largest= max(largest,(long long)arr[j]);
                sum+=(largest-smallest);
            }
        }
        return sum;
    }
};
