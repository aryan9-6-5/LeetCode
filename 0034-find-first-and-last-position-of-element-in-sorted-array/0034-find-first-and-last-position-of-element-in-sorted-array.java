class Solution {
    public int[] searchRange(int[] arr, int target) {
        int[] result={-1,-1};
        result[0]=firstindex(arr,target);
        result[1]=lastindex(arr,target);
        return result;
    }
     public int firstindex(int[] arr, int target) {
        int ans=-1;
        int start = 0, end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target <= arr[mid]){
                end = mid - 1;
            } 
            else{
                start = mid + 1;
            } 
            if(arr[mid]==target){
                ans=mid;
            } 
        }
        return ans;
     }
      public int lastindex(int[] arr, int target) {
        int ans=-1;
        int start = 0, end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target >= arr[mid]){
                start = mid + 1;
            } 
            else{
                end = mid - 1;
            } 
            if(arr[mid]==target){
                ans=mid;
            } 
        }
        return ans;
     }
}