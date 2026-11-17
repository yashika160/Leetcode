class Solution {
public:
    bool isAlphaNumeric(char c) {
        if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || c >= 'a' && c <= 'z') {
            return true;
        }
        return false;
    }

    char toLower(char c) {
        if(c >= 'A' && c <= 'Z') {
            return c + 32;
        }
        return c;
    }

    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;

        while(left < right) {
            while(left < right && !isAlphaNumeric(s[left])) {
                left++;
                continue;
            }
            while(left < right && !isAlphaNumeric(s[right])) {
                right--;
                continue;
            }

            if(toLower(s[left]) != toLower(s[right])) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};