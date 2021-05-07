#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

enum State { TOP, RIGHT, BOTTOM, LEFT };

State next_state(State s) {
  switch (s) {
  case TOP:
    return RIGHT;
  case RIGHT:
    return BOTTOM;
  case BOTTOM:
    return LEFT;
  case LEFT:
    return TOP;
  }
}

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
  vector<int> result;
  result.resize(r * c);

  int ri = 0;
  State state = TOP;

  int ymin = 0, xmin = 0;
  int xmax = c - 1, ymax = r - 1;

  while (ymin <= ymax and xmin <= xmax) {
    switch (state) {
    case TOP:
      for (int j = xmin; j <= xmax; ++j) {
        result[ri++] = matrix[ymin][j];
      }
      ymin++;
      break;
    case RIGHT:
      for (int i = ymin; i <= ymax; ++i) {
        result[ri++] = matrix[i][xmax];
      }
      xmax--;
      break;
    case BOTTOM:
      for (int j = xmax; j >= xmin; --j) {
        result[ri++] = matrix[ymax][j];
      }
      ymax--;
      break;
    case LEFT:
      for (int i = ymax; i >= ymin; --i) {
        result[ri++] = matrix[i][xmin];
      }
      xmin++;
      break;
    }

    state = next_state(state);
  }

  return result;
}

void solve() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> matrix(r, vector<int>(c, 0));

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> matrix[i][j];
    }
  }

  const auto result = spirallyTraverse(matrix, r, c);

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
