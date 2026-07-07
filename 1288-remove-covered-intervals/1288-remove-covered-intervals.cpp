class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int remaining = intervals.size();
        int maxEnd = 0;
        
        for (const auto& interval : intervals) {
            int end = interval[1];
            if (end <= maxEnd) {
                remaining--;
            } else {
                maxEnd = end;
            }
        }
        
        return remaining;
    }
};