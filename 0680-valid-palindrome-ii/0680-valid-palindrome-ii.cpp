class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                i += 1;
                j -= 1;
            } else
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1, f = 0;
        while (i < j) {
            if (s[i] == s[j]) {
                i += 1;
                j -= 1;
            } else {
                return (isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j));
            }
        }
        return true;
    }
};