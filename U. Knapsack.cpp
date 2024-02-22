// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include <iostream>
using namespace std;

int weight[104];
int value[104];

int dp[104][104];

int knapsack(int n, int w) {
  if (0 > n || w == 0)
    return 0;
  if (dp[n][w] != -1)
    return dp[n][w];
  int opt1 = 0, opt2 = 0;
  if (weight[n] <= w) {
    opt1 = knapsack(n - 1, w - weight[n]) + value[n];
  }
  opt2 = knapsack(n - 1, w);
  return dp[n][w] = max(opt1, opt2);
}

int main(int argc, char *argv[]) {
  int n, w;
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> weight[i] >> value[i];
  }
  for (int i = 0; i < 104; i++)
    for (int j = 0; j < 104; j++)
      dp[i][j] = -1;

  cout << knapsack(n - 1, w);
  return 0;
}
