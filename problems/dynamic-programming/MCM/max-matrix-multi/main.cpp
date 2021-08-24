#include <bits/stdc++.h>
using namespace std;

int helper(const vector<int> &numbers, int i, int j) {
  if (i >= j) {
    // less than or equal to 1 matrices selected, hence multiplication cost is 0
    return 0;
  }

  int mini = INT_MAX;
  for (int k = i; k < j; ++k) {
    int sub_cost = helper(numbers, i, k) + helper(numbers, k + 1, j);
    int this_op_cost = numbers[i - 1] * numbers[k] * numbers[j];

    mini = min(sub_cost + this_op_cost, mini);
  }

  return mini;
}

int helper_memo(const vector<int> &numbers, vector<vector<int>> &dp, int i,
                int j) {
  if (i >= j) {
    // less than or equal to 1 matrices selected, hence multiplication cost is 0
    return 0;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  int mini = INT_MAX;
  for (int k = i; k < j; ++k) {
    int sub_cost =
        helper_memo(numbers, dp, i, k) + helper_memo(numbers, dp, k + 1, j);
    int this_op_cost = numbers[i - 1] * numbers[k] * numbers[j];

    mini = min(sub_cost + this_op_cost, mini);
  }

  return dp[i][j] = mini;
}

int min_matrix_mult(const vector<int> &numbers) {
  // return helper(numbers, 1, numbers.size() - 1);
  const int N = numbers.size();
  vector<vector<int>> dp(N, vector<int>(N, -1));
  return helper_memo(numbers, dp, 1, N - 1);
}
void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);
  for (auto &num : numbers) {
    cin >> num;
  }

  cout << min_matrix_mult(numbers) << "\n";
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
