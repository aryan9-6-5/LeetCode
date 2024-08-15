class Solution {
    public int firstMissingPositive(int[] arr) {
        int i=0,length = arr.length;
        while(i<length){
            int correct_index=arr[i]-1;
            if (arr[i]>0 && correct_index<length && arr[i]!=arr[correct_index]){
                int temp=arr[i];
                arr[i]=arr[correct_index];
                arr[correct_index]=temp;
            }
            else i++;
        }
        for(i=0;i<length;i++){
            if(arr[i]!=i+1){
                return i+1;
            }
        }
        return length+1;
    }
}
