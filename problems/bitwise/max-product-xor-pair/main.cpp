#include <bits/stdc++.h>
using namespace std;

long long max_product_xp(long long C) {
  // example 13: 1101
  long long p2d = 1; // power of 2 greater than C: 10000
  while (p2d <= C) {
    p2d <<= 1;
  }

  long long Ai = p2d - 1;  // greatest number with msb equal to C's msb 1111
  long long mask = Ai ^ C; // 0 where C's bit is one 1101 -> 0010

  long long A = p2d >> 1; // 1000
  long long B = A - 1;    // 0111

  A = A ^ mask; // 1010: job to make bits of B zero

  return A * B;
}

void solve() {
  long long C;
  cin >> C;

  std::cout << max_product_xp(C) << "\n";
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
