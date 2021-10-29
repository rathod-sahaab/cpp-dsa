#include <bits/stdc++.h>
using namespace std;

int minimum_spaning_tree_cost(const vector<vector<pair<int, int>>> &graph) {
  const int N = graph.size();

  int mst_cost = 0;

  vector<int> dist(N, INT_MAX), parent(N, -1);
  vector<bool> in_mst(N, false);

  int in_mst_count = 0;

  dist[0] = 0;

  const auto get_min_index = [&dist, &in_mst]() {
    int min_index = -1, minimum = INT_MAX;
    for (int i = 0; i < dist.size(); ++i) {
      if (not in_mst[i] and minimum > dist[i]) {
        min_index = i;
        minimum = dist[i];
      }
    }
    return min_index;
  };

  while (in_mst_count < N) {
    int src = get_min_index();
    cout << src << "\n";
    in_mst_count++;
    in_mst[src] = true;

    mst_cost += dist[src];

    for (const auto &nei : graph[src]) {
      int dest = nei.first;
      int weight = nei.second;

      if (not in_mst[dest] and dist[dest] > weight) {
        dist[dest] = weight;
        parent[dest] = src;
      }
    }
  }

  return mst_cost;
}

void solve() {
  int N, E;
  cin >> N >> E;

  vector<vector<pair<int, int>>> graph(N);

  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  cout << minimum_spaning_tree_cost(graph) << "\n";
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
