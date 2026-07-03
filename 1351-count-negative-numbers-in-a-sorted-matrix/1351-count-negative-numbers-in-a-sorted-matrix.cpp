class Solution {
public:
    int binary(vector<int>& arr){
        int start=0;
        int end=arr.size()-1;
        while(start<end ){
            int mid=start+(end-start)/2;
            if(arr[mid]>=0)start=mid+1;
            else end = mid;
        }
        if(arr[start]<0) return start;
        return -1;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int a= 0;
        int ans=0;
        for(vector<int>& arr:grid){
            int n=arr.size();
            a=binary(arr);
            if(a!=-1)ans+=n-a;
        }
        return ans;
    }
};