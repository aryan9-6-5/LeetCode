class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(present(matrix[i],target)) return true;
        }
        return false;
    }
    bool present(vector<int> arr,int target){
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target<arr[mid]) end=mid-1;
            else if(target==arr[mid]) return true;
            else start=mid+1;
        }
        return false;
    }
};
