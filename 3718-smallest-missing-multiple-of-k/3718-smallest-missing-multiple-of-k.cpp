class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    unordered_set<int> hash;
    for (int x : nums) {
        hash.insert(x);
    }
    int check = k;
    for (int i = 1; i <= nums.size(); i++) {
        check =i* k;
        if (hash.find(check) == hash.end())
            return check;
    }
    return k * (nums.size() + 1);
}
};