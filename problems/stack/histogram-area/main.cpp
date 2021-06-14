#include <bits/stdc++.h>
using namespace std;

int max_histogram_area(vector<int> bar_heights) {

  const int N = bar_heights.size();

  vector<int> prev_small(N, 0), next_small(N, N); // nearest smaller

  {
    // next_small
    stack<int> s;
    for (int i = 0; i < N; ++i) {
      while (not s.empty() and bar_heights[s.top()] > bar_heights[i]) {
        next_small[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
  }
  {
    // prev_small
    stack<int> s;
    for (int i = N - 1; i >= 0; --i) {
      while (not s.empty() and bar_heights[s.top()] > bar_heights[i]) {
        prev_small[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
  }

  int max_area = 0;
  for (int i = 0; i < N; ++i) {
    int max_bar_area = (next_small[i] - prev_small[i] - 1) * bar_heights[i];
    max_area = max(max_area, max_bar_area);
  }
  return max_area;
}

void solve() {
  int N;
  cin >> N;

  vector<int> bar_heights(N);
  for (auto &bar : bar_heights) {
    cin >> bar;
  }

  cout << max_histogram_area(bar_heights) << "\n";
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
