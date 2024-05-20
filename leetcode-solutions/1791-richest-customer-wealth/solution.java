class Solution {   
        public static int maximumWealth(int[][] accounts) {
            int rowSumMax=Integer.MIN_VALUE;
            for (int[] account : accounts) {
                int rowSum=0;
                for (int j :account) {
                    rowSum += j;
                }
                if (rowSumMax < rowSum)
                    rowSumMax = rowSum;
            }
            return rowSumMax;
        }
}
