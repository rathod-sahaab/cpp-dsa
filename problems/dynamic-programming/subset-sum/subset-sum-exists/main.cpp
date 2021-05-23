#include <bits/stdc++.h>
using namespace std;

bool subset_sum_iter(const vector<int> &numbers, const int sum) {
  int N = numbers.size();

  vector<vector<bool>> table(N + 1, vector<bool>(sum + 1, -1));

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= sum; ++j) {
      if (j == 0) {
        table[i][j] = true;
        continue;
      }
      if (i == 0) {
        table[i][j] = false;
        continue;
      }

      if (numbers[i - 1] <= j) {
        table[i][j] = table[i - 1][j] or table[i - 1][j - numbers[i - 1]];
        continue;
      }
      table[i][j] = table[i - 1][j];
    }
  }

  return table[N][sum];
}

bool subset_sum_recur(const vector<int> &numbers, const int sum, int n) {
  if (sum == 0) {
    return true;
  }
  if (n == 0) {
    return false;
  }

  if (numbers[n - 1] <= sum) {
    return subset_sum_recur(numbers, sum, n - 1) or
           subset_sum_recur(numbers, sum - numbers[n - 1], n - 1);
  }

  return subset_sum_recur(numbers, sum, n - 1);
}

bool subset_sum(const vector<int> &numbers, const int sum) {
  return subset_sum_recur(numbers, sum, numbers.size());
}

void solve() {
  int N, sum;
  cin >> N >> sum;
  vector<int> numbers(N);

  for (auto &num : numbers) {
    cin >> num;
  }

  bool exists = subset_sum(numbers, sum);
  bool iter_exists = subset_sum_iter(numbers, sum);

  cout << (exists ? "YES " : "NO ") << (iter_exists ? "YES " : "NO ") << "\n";
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
