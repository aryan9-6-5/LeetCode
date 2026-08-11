class Solution {
public:
    bool cansplit(vector<int>& arr, int k, int maxsum){
        int csum=0;
        int count=1;
        for(int x: arr){
            if(csum+x>maxsum){
                count++;
                csum=x;
                if(count>k)return false;
            }
            else csum+=x;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0,h=0;
        for(int x: nums){
            l=max(l, x);
            h+=x;
        }
        while(l<h){
            long long mid= l+(h-l)/2;
            if(cansplit(nums,k,mid)){
                h=mid;
            }
            else l=mid+1;
        }
        return (int) l;
    }
};