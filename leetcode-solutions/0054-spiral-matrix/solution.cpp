class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        
        if (arr.empty() || arr[0].empty()) return {};

        int m = (int)arr.size();
        int n = (int)arr[0].size();
        int top = 0, left = 0, right = n - 1, bottom = m - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            // left to right
            for (int i = left; i <= right; i++) {
                ans.push_back(arr[top][i]);
            }
            top++;

            // top to bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(arr[i][right]);
            }
            right--;

            // right to left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(arr[bottom][i]);
                }
                bottom--;
            }

            // bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(arr[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

