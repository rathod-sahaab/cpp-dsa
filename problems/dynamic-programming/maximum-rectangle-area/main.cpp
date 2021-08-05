#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int max_histogram_area(const vector<int> &heights) {
  const int N = heights.size();
  vector<int> next_lesser_el(N, N);
  {
    stack<int> s;

    for (int i = 0; i < N; ++i) {
      while (not s.empty() and heights[s.top()] > heights[i]) {
        int greater = s.top();
        s.pop();
        next_lesser_el[greater] = i;
      }
      s.push(i);
    }
  }

  vector<int> prev_lesser_el(N, -1);
  {
    stack<int> s;
    for (int i = N - 1; i >= 0; --i) {
      while (not s.empty() and heights[s.top()] > heights[i]) {
        int greater = s.top();
        s.pop();
        prev_lesser_el[greater] = i;
      }
      s.push(i);
    }
  }

  int maxi = 0;
  for (int i = 0; i < N; ++i) {
    int curr = heights[i] * (next_lesser_el[i] - prev_lesser_el[i] - 1);
    maxi = max(curr, maxi);
  }
  return maxi;
}

int max_area_reactangle(const vector<vector<int>> &matrix) {
  const int N = matrix.size();
  const int M = matrix[0].size();

  vector<int> heights(M, 0);

  int maxi = 0;
  for (const auto &row : matrix) {
    for (int i = 0; i < M; ++i) {
      heights[i] = row[i] == 0 ? 0 : row[i] + heights[i];
    }

    const int mha = max_histogram_area(heights);
    maxi = max(maxi, mha);
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

  cout << max_area_reactangle(matrix) << "\n";
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
