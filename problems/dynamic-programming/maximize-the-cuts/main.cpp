#include <bits/stdc++.h>
using namespace std;

int maximizeTheCuts(vector<int> &dp, int n, int x, int y, int z) {
  if (n == 0)
    return 0;

  if (dp[n] != -1) {
    return dp[n];
  }

  int xcut = xcut <= n ? maximizeTheCuts(dp, n - x, x, y, z) : 0;
  int ycut = ycut <= n ? maximizeTheCuts(dp, n - y, x, y, z) : 0;
  int zcut = zcut <= n ? maximizeTheCuts(dp, n - z, x, y, z) : 0;

  return dp[n] = 1 + max({xcut, ycut, zcut});
}

int maximizeTheCuts(int n, int x, int y, int z) {
  vector<int> dp(n + 1, -1);
  return maximizeTheCuts(dp, n, x, y, z);
}

int maximizeTheCuts_iter(int n, int x, int y, int z) {
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int max_of_xyz_cut = -1;

    if (i >= x and dp[i - x] != -1) {
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

  cout << maximizeTheCuts_iter(N, x, y, z) << "\n";
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
