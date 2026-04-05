#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
public:
    struct State {
        int count;    
        long long cost; 
        
        bool operator>(const State& other) const {
            if (count != other.count) return count > other.count;
            return cost < other.cost;
        }
    };

    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<array<State, 2>> dp(n, {{{0, 0LL}, {-1, 0LL}}});

        dp[0][0] = {0, 0LL};

        for (int i = 1; i < n - 1; i++) {
            State a = dp[i - 1][0];
            State b = dp[i - 1][1];
            dp[i][0] = (a > b) ? a : b;

            if (dp[i - 1][0].count != -1) {
                long long target = max(nums[i - 1], nums[i + 1]) + 1LL;
                long long opsNeeded = max(0LL, target - nums[i]);
                
                dp[i][1] = {dp[i - 1][0].count + 1, dp[i - 1][0].cost + opsNeeded};
            }
        }

        State finalA = dp[n - 2][0];
        State finalB = dp[n - 2][1];
        State best = (finalA > finalB) ? finalA : finalB;

        return best.cost;
    }
};
