#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int lis_iter(const vector<int> &numbers) {
  vector<int> result(numbers.size(), 1);

  result[0] = 1;

  for (int i = 1; i < result.size(); ++i) {
    for (int j = i - 1; j >= 0; j--) {
      if (numbers[i] > numbers[j]) {
        result[i] = max(result[i], 1 + result[j]);
      }
    }
  }

  return *max_element(result.cbegin(), result.cend());
}

int lis_recur(const vector<int> numbers, int i) {
  if (i == 0) {
    return 1;
  }
  int max_pred = 0;
  for (int j = i - 1; j >= 0; j--) {
    if (numbers[i] > numbers[j]) {
      max_pred = max(max_pred, lis_recur(numbers, j));
    }
  }
  return 1 + max_pred;
}

int lis_recur(const vector<int> numbers) {
  int max_lis = 1;
  for (int i = 0; i < numbers.size(); ++i) {
    max_lis = max(max_lis, lis_recur(numbers, i));
  }

  return max_lis;
}

void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);

  for (auto &num : numbers) {
    cin >> num;
  }

  cout << lis_iter(numbers) << " " << lis_recur(numbers) << "\n";
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
