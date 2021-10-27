#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

class DisjointSetUnion {
public:
  // constructors, asssignment, destructor
  DisjointSetUnion(int N) : parent(N), size(N, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int a) {
    if (a == parent[a]) {
      return a;
    }
    return a = find(parent[a]);
  }

  void join(int a, int b) {
    int finda = find(a);
    int findb = find(b);
    if (finda != findb) {
      if (size[a] >= size[b]) {
        parent[findb] = finda;
      } else {
        parent[finda] = findb;
      }
    }
  }

  bool connected(int a, int b) { return find(a) == find(b); }

private:
  vector<int> parent;
  vector<int> size;
};

int minimum_spaning_tree_cost(DisjointSetUnion &dsu,
                              vector<vector<int>> &edges) {
  // 1. sort
  sort(edges.begin(), edges.end());

  // 2. check for each edge
  int cost = 0;
  for (const auto &edge : edges) {
    int w = edge[0];
    int u = edge[1];
    int v = edge[2];

    if (not dsu.connected(u, v)) {
      cost += w;
      dsu.join(u, v);
    }
  }

  return cost;
}

void solve() {
  int N, E;
  cin >> N >> E;

  vector<vector<int>> edges;
  edges.reserve(E);

  DisjointSetUnion dsu(N);

  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    edges.push_back({w, u, v});
  }

  cout << minimum_spaning_tree_cost(dsu, edges) << "\n";
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
