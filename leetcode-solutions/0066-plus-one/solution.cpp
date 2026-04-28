class Solution {
public:
    vector<int> reversev(vector<int>& v) {
        int left = 0;
        int right = v.size() - 1;

        while(left < right) {
            int temp = v[left];
            v[left] = v[right];
            v[right] = temp;
            left++;
            right--;
        }
        return v;
    }
    vector<int> plusOne(vector<int>& arr) {
        int n=arr.size();
        int carry=1;
        for(int i=n-1;i>=0 && carry!=0;i--){
            int sum=carry+arr[i];
            arr[i]=sum%10;
            carry=sum/10;
        }
        if(carry!=0){
            arr.push_back(carry);
            return reversev(arr);
        }
        return arr;
    }
};
