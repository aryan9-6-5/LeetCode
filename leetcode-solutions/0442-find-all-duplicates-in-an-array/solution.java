import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findDuplicates(int[] arr) {
        List<Integer> list= new ArrayList<>();
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
        for (i = 0; i < length; i++) {
            if (i!=arr[i]-1){
                list.add(arr[i]);
            }
        }
        return list;
    }
}
