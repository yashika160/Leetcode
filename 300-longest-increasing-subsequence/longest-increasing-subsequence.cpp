class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        vector<int> dp(n);
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            answer = max(answer, dp[i]);
        }
        return answer;
    }
};