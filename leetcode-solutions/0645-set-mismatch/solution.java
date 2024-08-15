class Solution {
    public int[] findErrorNums(int[] arr) {
        int i=0,length = arr.length;
        while(i<length){
            int correct_index=arr[i]-1;
            if (correct_index<length && arr[i]!=arr[correct_index]){
                int temp=arr[i];
                arr[i]=arr[correct_index];
                arr[correct_index]=temp;
            }
            else i++;
        }
    for(i=0;i<length;i++){
        if(arr[i]!=i+1){
            return new int[]{arr[i],i+1};
        }
    }
    return new int[]{-1,-1};
    }
}
