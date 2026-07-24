class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        unordered_set<int> pairXor, tripletXor;

        for (int i = 0; i < n; i++) {
            tripletXor.insert(nums[i]);
            for (int j = i + 1; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        for (int p : pairXor) {
            for (int x : nums) {
                tripletXor.insert(p ^ x);
            }
        }

        return tripletXor.size();
    }
};