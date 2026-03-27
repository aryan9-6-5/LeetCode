class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        int maxh=0;
        while(left<right){
            int height=min(arr[left],arr[right]);
            int width=right-left;
            int area=height*width;
            maxh=max(maxh,area);
            if(arr[left]<arr[right])left++;
            else right--;
        }
        return maxh;
    }
};
