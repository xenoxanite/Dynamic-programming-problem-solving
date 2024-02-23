// https://leetcode.com/problems/min-cost-climbing-stairs/

// @leet start
class Solution {
public:
  int dp[100000];
  int min_cost(vector<int> cost, int n) {
    if (n < 0)
      return 0;
    if (dp[n] != -1)
      return dp[n];
    int opt1 = 0, opt2 = 0;
    if (n - 1 >= 0)
      opt1 = min_cost(cost, n - 1) + cost[n - 1];
    if (n - 2 >= 0)
      opt2 = min_cost(cost, n - 2) + cost[n - 2];
    return dp[n] = min(opt1, opt2);
  }
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    for (int i = 0; i <= n; i++) {
      dp[i] = -1;
    }
    return min_cost(cost, n);
  }
};
// @leet end
