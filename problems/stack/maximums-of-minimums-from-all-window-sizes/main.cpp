#include <bits/stdc++.h>
using namespace std;

void left_and_right_minis(const vector<int> &numbers, vector<int> &left_minimum,
                          vector<int> &right_minimum) {
  const auto N = numbers.size();

  stack<int> s;

  for (int i = 0; i < N; ++i) {
    while (not s.empty() and numbers[s.top()] > numbers[i]) {
      const auto temp = s.top();
      s.pop();
      right_minimum[temp] = i;
    }

    s.push(i);
  }

  while (not s.empty()) {
    s.pop();
  }

  for (int i = N - 1; i >= 0; --i) {
    while (not s.empty() and numbers[s.top()] > numbers[i]) {
      const auto temp = s.top();
      s.pop();
      left_minimum[temp] = i;
    }

    s.push(i);
  }
}

vector<int> maxi_of_minis(const vector<int> &numbers) {
  const auto N = numbers.size();
  vector<int> result(N, 0);

  vector<int> left_minimum(N, -1);
  vector<int> right_minimum(N, N);

  left_and_right_minis(numbers, left_minimum, right_minimum);

  // iterate over all numbers
  for (int i = 0; i < N; ++i) {
    const auto len = right_minimum[i] - left_minimum[i] - 1;
    // max size of window in which the number is minimum

    result[len - 1] = max(result[len - 1], numbers[i]);
    // other numbers may also be minimum for this size window
    // so we pick maximum to those
  }

  /**
   * if there is no such number which is minimum for a window size let's say
   * 6, the answer would be answer of window size 7
   * Window size N will exists as all elements are included and there would be
   * atleast one such elements smaller than all other
   */
  for (int i = N - 2; i >= 0; --i) {
    result[i] = max(result[i], result[i + 1]);
  }

  return result;
}

void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);

  for (auto &num : numbers) {
    cin >> num;
  }

  const vector<int> result = maxi_of_minis(numbers);

  copy(std::begin(result), std::end(result),
       std::ostream_iterator<decltype(result[0])>{std::cout, " "});
  std::cout << "\n";
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
