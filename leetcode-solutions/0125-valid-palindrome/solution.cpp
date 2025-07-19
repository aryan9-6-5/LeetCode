class Solution {
#include<string>
#include<cctype>
public:
    string clean(const string& input) {
        string result;
        for (char ch : input) {
            if (isalnum(static_cast<unsigned char>(ch))) {
                result += tolower(static_cast<unsigned char>(ch));
            }
        }
        return result;
    }
    bool isPalindrome(string s) {
        s=clean(s);
        int start=0;
        int end=s.length()-1;
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    // bool isPalindrome(string s) {
    //     s = clean(s);
    //     int start = 0;
    //     int end = s.length() - 1;

    //     while (start <= end) {
    //         if (s[start] != s[end]) return false;
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }
};
