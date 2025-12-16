class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& arr) {
        int n=arr.size();
        prefix.resize(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=arr[i]+prefix[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
