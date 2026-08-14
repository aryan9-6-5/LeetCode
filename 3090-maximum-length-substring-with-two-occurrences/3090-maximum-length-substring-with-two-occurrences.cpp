class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>hash;
        int maxlen=0;
        int left=0,right=0;
        while(right<s.length()){
            hash[s[right]]++;
            while(hash[s[right]]>2){
                hash[s[left]]--;
                left++;
            }
            maxlen=max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};