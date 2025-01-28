class Solution {
    public int removeDuplicates(int[] arr) {
        if (arr.length == 0) return 0;
        int index = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[index]) {
                index++;
                arr[index] = arr[i];
            }
        }
        return index + 1;
    }
}

