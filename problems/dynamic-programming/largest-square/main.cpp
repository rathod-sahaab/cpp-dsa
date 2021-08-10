#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int largest_square(const vector<vector<int>> &matrix) {
  const int N = matrix.size();
  const int M = matrix[0].size();

  vector<vector<int>> max_sq(matrix);

  int maxi = 0;

  for (int i = N - 2; i >= 0; --i) {
    for (int j = M - 2; j >= 0; --j) {
      if (max_sq[i][j] != 0) {
        max_sq[i][j] =
            1 + min({max_sq[i + 1][j], max_sq[i + 1][j + 1], max_sq[i][j + 1]});
      }
    }
  }

  for (const auto &row : max_sq) {
    for (const auto elem : row) {
      maxi = max(maxi, elem);
    }
  }

  return maxi;
}

void solve() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> matrix(N, vector<int>(M));

  for (auto &row : matrix) {
    for (auto &elem : row) {
      cin >> elem;
    }
  }

  cout << largest_square(matrix) << "\n";
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
