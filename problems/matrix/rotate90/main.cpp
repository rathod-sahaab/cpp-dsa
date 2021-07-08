#include <bits/stdc++.h>
#include <vector>
using namespace std;

/**
 *
 * 1 2 3 4    1 5 9 F    F 9 5 1
 * 5 6 7 8 -> 2 6 0 D -> D 0 6 2
 * 9 0 A B    3 7 A E    E A 7 3
 * C D E F    4 8 B F    F B 8 4
 */
void rotate90(vector<vector<int>> &matrix) {
  // Transpose along main axis then flip around y-axis
  const int N = matrix.size();

  // Transpose
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Flip
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N / 2; ++j) {
      swap(matrix[i][j], matrix[i][N - 1 - j]);
    }
  }
}

void solve() {
  int N;
  cin >> N;

  vector<vector<int>> matrix(N, vector<int>(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> matrix[i][j];
    }
  }

  rotate90(matrix);

  for (const auto &row : matrix) {
    copy(std::begin(row), std::end(row),
         std::ostream_iterator<decltype(row[0])>{std::cout, " "});
    std::cout << "\n";
  }
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
