class Solution {
    public List<Integer> findDisappearedNumbers(int[] arr) {
        int i=0;
        while(i<arr.length){
            int correct_index=arr[i]-1;
            if(correct_index<arr.length && arr[i]!=arr[correct_index]){
                int temp=arr[i];
                arr[i]=arr[correct_index];
                arr[correct_index]=temp;
            }
            else i++;
        }
        List<Integer> list = new ArrayList<>();
        for(i=0;i<arr.length;i++){
            if(arr[i]!=i+1){
                list.add(i+1);
            }
        }
        return list;
    }
}
