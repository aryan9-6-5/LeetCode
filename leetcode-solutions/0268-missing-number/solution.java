class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        int xor=0;
        int xorArr=0;
        for(int num:arr){
            xorArr^=num;
        }
        for(int i=1;i<=n;i++){
            xor^=i;
        }
        return xor^xorArr;
    }
}
