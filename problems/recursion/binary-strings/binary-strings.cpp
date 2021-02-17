#include <bits/stdc++.h>
using namespace std;

void binary_string(int N, string osf = "") {
  if (N == 0) {
    cout << osf << "\n";
    return;
  }

  binary_string(N - 1, osf + '0');

  if (osf.back() != '1') {
    // only run if last digit was not 0
    binary_string(N - 1, osf + '1');
  }
}

int main() {

  int n;
  do {
    cout << "Enter length of binary string: ";
    cin >> n;
    binary_string(n);
    cout << "________DONE________\n";
  } while (n != -1);
}
