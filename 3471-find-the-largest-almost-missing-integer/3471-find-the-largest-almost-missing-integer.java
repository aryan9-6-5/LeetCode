class Solution {
    public int largestInteger(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer,Integer> hash= new HashMap<>();
        for( int i=0;i<=n-k;i++){
            HashSet<Integer> check= new HashSet<>();
            for( int j=i;j<i+k;j++){
                check.add(nums[j]);
            }
            for(int x: check){
                hash.put(x,hash.getOrDefault(x,0)+1);
            }
        }
        int ans=-1;
        for(Map.Entry<Integer, Integer> entry: hash.entrySet()){
            if( entry.getValue()==1){
                ans=Math.max(ans, entry.getKey());
            }
        }
        return ans;
    }
}