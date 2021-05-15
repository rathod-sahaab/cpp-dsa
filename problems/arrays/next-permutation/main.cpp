#include <algorithm>
#include <array>
#include <bits/stdc++.h>
using namespace std;

void next_permutation_custom(vector<int> &numbers) {
  int break_index = -1;
  for (int i = numbers.size() - 2; i >= 0; --i) {
    if (numbers[i] < numbers[i + 1]) {
      break_index = i;
      break;
    }
  }

  if (break_index == -1) {
    reverse(numbers.begin(), numbers.end());
    return;
  }

  for (int i = numbers.size() - 1; i > break_index; ++i) {
    if (numbers[i] > numbers[break_index]) {
      swap(numbers[i], numbers[break_index]);
      break;
    }
  }

  reverse(numbers.begin() + break_index + 1, numbers.end());
}

void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);
  string number_text;

  cin >> number_text;

  // seperate out digits
  transform(number_text.begin(), number_text.end(), numbers.begin(),
            [](char c) { return c - '0'; });

  next_permutation_custom(numbers);

  copy(std::begin(numbers), std::end(numbers),
       std::ostream_iterator<decltype(numbers[0])>{std::cout, " "});
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
