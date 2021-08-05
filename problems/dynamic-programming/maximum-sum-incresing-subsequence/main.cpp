#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int max_sum_inc_subseq(const vector<int> &numbers) {
  const int N = numbers.size();

  vector<int> msis(numbers);

  for (int i = 0; i < N; ++i) {
    int maxi = 0;
    for (int j = 0; j < i; ++j) {
      if (numbers[i] > numbers[j]) {
        maxi = max(maxi, msis[j]);
      }
    }
    msis[i] = maxi + numbers[i];
  }

  return *max_element(msis.begin(), msis.end());
}

void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);
  for (auto &num : numbers) {
    cin >> num;
  }

  cout << max_sum_inc_subseq(numbers) << "\n";
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
