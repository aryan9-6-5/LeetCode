// class Solution {
//     public int maxArea(int[] arr) {
//         int length=arr.length;
//         int max=length-1,min=0;
//         int water=0;
//         while (min<max){
//             int height=arr[min]<arr[max]?arr[min]:arr[max];
//             int width=max-min;
//             if (water<(height*width)){
//                 water=height*width;
//             }
//             if (arr[min]<arr[max]) min++;
//             else max--;
//         }
//         return water;
//     }
// }

class Solution {
    public int maxArea(int[] arr) {
        int maxWater=0;
        int n=arr.length;
        int left=0,right=n-1;
        while(left<right){
            int height=Math.min(arr[left],arr[right]);
            int width=right-left;
            int currWater=height*width;
            maxWater=Math.max(maxWater,currWater);
            if(arr[left]<arr[right])left++;
            else right--;
        }
        return maxWater;
    }
}
