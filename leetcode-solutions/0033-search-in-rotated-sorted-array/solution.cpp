class Solution {
public:
int find(vector<int>& arr) {
    int start = 0, end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[end])
            start = mid + 1;
        else
            end = mid;
    }
    return (start - 1 + arr.size()) % arr.size();
}
    int search(vector<int>& arr, int target) {
        if (arr.size() == 0) return -1; 
        int start = 0;
        int end= arr.size()-1;
        int peak=find(arr);
        if (peak == -1) peak = arr.size() - 1;
        if(target>=arr[0] && target<=arr[peak]) end=peak;
        else start=peak+1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]<target) start=mid+1;
            else end=mid-1;
        }
        return -1;
    }
};
