class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        int[] count = new int[n+1];
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(count[i]==0){
                return i;
            }
        }
        return n;
    }
}
