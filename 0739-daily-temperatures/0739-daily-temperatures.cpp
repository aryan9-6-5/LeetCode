class Solution {
public:
vector<int> nge(vector<int>& nums, vector<int>& result) {
    int n = nums.size();
    stack<int> st; 
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] =i-st.top() ;
            st.pop();
        }
        st.push(i);
    }
    return result;
}
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> ans(arr.size(),0);
        return nge(arr, ans);
    }
};

