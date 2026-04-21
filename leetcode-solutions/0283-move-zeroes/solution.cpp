class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int start=0;
        int end=0;
        int n=arr.size();
        while(start<n){
            if(arr[start]!=0){
                swap(arr[start],arr[end]);
                end++;
            }
            start++;
        }
    }
};
