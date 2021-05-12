#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater_element(const vector<int> &numbers) {
  vector<int> result(numbers.size(), -1);

  stack<int> s; // index

  for (int i = 0; i < numbers.size(); ++i) {
    while (not s.empty() and numbers[s.top()] < numbers[i]) {
      result[s.top()] = numbers[i];
      s.pop();
    }
    s.push(i);
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

  const auto result = next_greater_element(numbers);

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
