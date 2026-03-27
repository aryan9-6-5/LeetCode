class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int start=0;
        int end=0;
        while(start<arr.size()){
                if(arr[start]!=0){
                    swap(arr[start],arr[end]);
                    end++;
                }
                start++;
            }
        }
};
