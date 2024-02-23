// https://www.spoj.com/problems/FARIDA/en/

#include <iostream>
using namespace std;
int dp[1000];
int max_amount(int nums[], int n) {
  if (n < 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  int opt1 = max_amount(nums, n - 2) + nums[n];
  int opt2 = max_amount(nums, n - 1);
  return dp[n] = max(opt1, opt2);
}

int main(int argc, char *argv[]) {
  int testcases;
  cin >> testcases;
  for (int ii = 1; ii <= testcases; ii++) {
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++) {
      cin >> Arr[i];
      dp[i] = -1;
    }
    cout << "Case " << ii << ": " << max_amount(Arr, n - 1) << endl;
  }
  return 0;
}
