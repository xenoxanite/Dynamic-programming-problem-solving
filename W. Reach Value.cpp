// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W
#include <iostream>
using namespace std;

bool knapsack(long long int n, long long int target) {
  if (n > target)
    return false;
  else if (n == target)
    return true;
  bool opt1 = knapsack(n * 10, target);
  bool opt2 = knapsack(n * 20, target);
  return (opt1 || opt2);
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    long long int a;
    cin >> a;
    cout << (knapsack(1, a) ? "YES" : "NO") << endl;
  }
  return 0;
}
