class Solution {
    public int chalkReplacer(int[] arr, int k) {
        int i=0,len= arr.length;
        while(k >=arr[i]){
            k-=arr[i];
            i++;
            if (i==len) i=0;
        }
        return i;
    }
}