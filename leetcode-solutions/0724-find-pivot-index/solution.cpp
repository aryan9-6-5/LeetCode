class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        vector<int> leftsum;
        vector<int> rightsum;
        int n=arr.size();
        int left=0;
        int right=n-1;
        int ans=-1;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            l+=arr[i];
            leftsum.push_back(l);
        }
        for(int i=0;i<n;i++){
            r=l;
            l=l-arr[i];
            rightsum.push_back(r);
        }
        for(int i=0;i<n;i++){
            if(leftsum[i]==rightsum[i]){
                ans=i;
                break;
            } 
        }
        return ans;
    }
};
