class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rows, cols;
        rows.reserve(buildings.size()*2);
        cols.reserve(buildings.size()*2);
        for (auto &p : buildings) {
            int x = p[0], y = p[1];
            rows[x].push_back(y);
            cols[y].push_back(x);
        }
        for (auto &kv : rows) sort(kv.second.begin(), kv.second.end());
        for (auto &kv : cols) sort(kv.second.begin(), kv.second.end());

        int ans = 0;
        for (auto &p : buildings) {
            int x = p[0], y = p[1];
            auto &ry = rows[x];
            auto &cx = cols[y];
            if (ry.front() < y && y < ry.back() &&
                cx.front() < x && x < cx.back()) {
                ++ans;
            }
        }
        return ans;
    }
};

