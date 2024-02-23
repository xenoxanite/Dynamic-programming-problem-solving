// https://leetcode.com/problems/house-robber/

// @leet start
class Solution {
public:
  int dp[1000];
  int max_amount(vector<int> &nums, int n) {
    if (n < 0)
      return 0;
    if(dp[n] != -1) return dp[n];
    int opt1 = max_amount(nums, n - 2) + nums[n];
    int opt2 = max_amount(nums, n - 1);
    return dp[n] = max(opt1, opt2);
  }
  int rob(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i <= n; i++)
      dp[i] = -1;
    return max_amount(nums, n - 1);
  }
};
// @leet end
