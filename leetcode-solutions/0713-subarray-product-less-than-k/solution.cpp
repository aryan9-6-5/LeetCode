class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        if(k<=1) return 0;
        int i=0,j=0;
        int n=arr.size();
        int count=0;
        int current=1;
        for(int j=0;j<n;j++){
            current*=arr[j];
            while(current>=k){
                current/=arr[i];
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
};
