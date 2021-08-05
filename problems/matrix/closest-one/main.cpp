#include <bits/stdc++.h>
using namespace std;

struct CordDist {
  int i;
  int j;
  int d; // distance from one
};

vector<vector<int>> min_distance(vector<vector<int>> &grid) {
  const int N = grid.size();
  const int M = grid[0].size();

  vector<vector<int>> result(N, vector<int>(M, INT_MAX));
  vector<vector<bool>> visited(N, vector<bool>(M, false));

  queue<CordDist> q;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 1) {
        q.push({i, j, 0});
        visited[i][j] = true;
      }
    }
  }

  while (not q.empty()) {
    CordDist cd = q.front();
    q.pop();

    int i = cd.i;
    int j = cd.j;

    result[i][j] = cd.d;

    vector<pair<int, int>> vns = {
        {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};

    for (const auto vn : vns) {
      const int i = vn.first;
      const int j = vn.second;
      if (i >= 0 and i < N and j >= 0 and j < M) {
        if (not visited[i][j]) {
          visited[i][j] = true;
          q.push({i, j, cd.d + 1});
        }
      }
    }
  }

  return result;
}

void solve() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> grid(N, vector<int>(M));

  for (auto &row : grid) {
    for (auto &elem : row) {
      cin >> elem;
    }
  }

  auto result = min_distance(grid);

  for (const auto &row : result) {
    for (const int elem : row) {
      cout << elem << " ";
    }
    cout << "\n";
  }
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    solve();
  }
}
