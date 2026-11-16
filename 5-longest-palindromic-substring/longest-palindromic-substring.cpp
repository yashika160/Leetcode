class Solution {
public:

    int end = 0;
    int maxLen = 0;

    int solve(string &s, string &rev, int i, int j, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i - 1] == rev[j - 1]) {
            dp[i][j] = 1 + solve(s, rev, i - 1, j - 1, dp);
        }
        else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                int len = solve(s, rev, i, j, dp);
                int start = i - len;
                int orgStart = n - j;
                if(len > 0 && start == orgStart) {
                    if(len > maxLen) {
                        maxLen = len;
                        end = i - 1;
                    }
                }
            }
        }
        return s.substr(end - maxLen + 1, maxLen);
    }
};