class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        int left=0,right=0;
        int n=arr.size();
        int ans=1;
        unordered_map<int,int>hash;
        while(right<n){
            hash[arr[right]]++;
            if(hash[arr[right]]>k ){
                while(arr[left]!=arr[right]){
                    hash[arr[left]]--;
                    left++;
                }
                hash[arr[left]]--;
                left++; 
            }
            ans=max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};