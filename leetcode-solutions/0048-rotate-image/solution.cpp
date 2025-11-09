class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            int start=0,end=n-1;
            while(start<end){
                swap(arr[i][start],arr[i][end]);
                start++;
                end--;
            }
        }
    }
};
