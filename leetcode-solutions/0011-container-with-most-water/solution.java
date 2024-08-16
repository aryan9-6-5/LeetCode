class Solution {
    public int maxArea(int[] arr) {
        int length=arr.length;
        int max=length-1,min=0;
        int water=0;
        while (min<max){
            int height=arr[min]<arr[max]?arr[min]:arr[max];
            int width=max-min;
            if (water<(height*width)){
                water=height*width;
            }
            if (arr[min]<arr[max]) min++;
            else max--;
        }
        return water;
    }
}

