#include <bits/stdc++.h>
using namespace std;

int maximize_the_cuts(int n, int x, int y, int z) {
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int max_of_xyz_cut = -1;
    // if dp[i - {x,y,z}] is '-1' it's invalid i.e.
    // it cannot be split in parts of x, y, z lengths

    if (i >= x and dp[i - x] != -1) {
      // length of rod is greater than cut and resultant is splitable length
      max_of_xyz_cut = max(1 + dp[i - x], max_of_xyz_cut);
    }
    if (i >= y and dp[i - y] != -1) {
      max_of_xyz_cut = max(1 + dp[i - y], max_of_xyz_cut);
    }
    if (i >= z and dp[i - z] != -1) {
      max_of_xyz_cut = max(1 + dp[i - z], max_of_xyz_cut);
    }

    dp[i] = max_of_xyz_cut;
  }

  return dp[n];
}

void solve() {
  int N;
  cin >> N;

  int x, y, z;
  cin >> x >> y >> z;

  cout << maximize_the_cuts(N, x, y, z) << "\n";
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
