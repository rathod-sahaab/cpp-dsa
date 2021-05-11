#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &number, int multiply_by) {
  int carry = 0;
  for (auto &digit : number) {
    int mult = digit * multiply_by + carry;
    carry = mult / 10;
    digit = mult % 10;
  }
  // carry 254
  while (carry) {
    number.push_back(carry % 10);
    carry /= 10;
  }
}

vector<int> factorial(int N) {
  vector<int> fact{1};
  for (int i = 2; i <= N; i++) {
    multiply(fact, i);
  }
  return fact;
}

void solve() {
  int N;
  cin >> N;

  const auto result = factorial(N);

  // print the number
  copy(result.crbegin(), result.crend(),
       std::ostream_iterator<decltype(result[0])>{std::cout, ""});
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
