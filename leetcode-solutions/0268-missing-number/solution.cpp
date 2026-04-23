class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        while(i<n){
            int correct=arr[i];
            if(correct < n && arr[i]!=arr[correct]){
                swap(arr[i],arr[correct]);
            }
            else i++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i) return i;
        }
        return n;
    }
};
