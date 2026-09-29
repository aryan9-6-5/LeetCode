class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> dict;
        int i = 0, j = 0;
        for (int k = 0; k < s1.length(); k++) {
            dict[s1[k]]++;
        }
        int uniqueCharacters = dict.size();
        while (j < s2.length()) {
            if (dict.find(s2[j]) != dict.end()) {
                dict[s2[j]]--;
                if (dict[s2[j]] == 0)
                    uniqueCharacters--;
            }
            if (j - i + 1 == s1.length()) {
                if (uniqueCharacters == 0)
                    return true;
                if (dict.find(s2[i]) != dict.end()) {
                    dict[s2[i]]++;
                    if (dict[s2[i]] == 1)
                        uniqueCharacters++;
                }
                i++;
            }
            j++;
        }
        return false;
    }
};