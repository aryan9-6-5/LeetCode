class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int ans=arr[0]+arr[1]+arr[2];
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<=n-3;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int cur=arr[i]+arr[j]+arr[k];
                if(abs(target-cur)<abs(target-ans)){
                    ans=cur;
                }
                if(cur>target)k--;
                else if(cur<target)j++;
                else return target;
            }
        }
        return ans;
    }
};
