class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int sum=0;
        map<int,int> presum;
        presum[0]=1;
        int count=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int check=sum-k;
            count+=presum[check];
            presum[sum]+=1;
        }
        return count;
    }
};
