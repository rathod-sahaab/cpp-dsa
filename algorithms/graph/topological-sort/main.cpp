#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> topological_sort(const vector<vector<int>> &directed_graph,
                             vector<int> indegree) {
  const int n_nodes = directed_graph.size();

  queue<int> q;
  for (int i = 0; i < n_nodes; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> result;
  while (not q.empty()) {
    const int curr = q.front();
    q.pop();

    result.push_back(curr);

    for (const auto d : directed_graph[curr]) {
      indegree[d]--;
      if (indegree[d] == 0) {
        q.push(d);
      }
    }
  }

  return result;
}

void solve() {
  int n_nodes, n_edges;
  cin >> n_nodes >> n_edges;

  vector<vector<int>> directed_graph(n_nodes);
  vector<int> indegree(n_nodes, 0);

  for (int i = 0; i < n_edges; ++i) {
    int src, dest;
    cin >> src >> dest;

    directed_graph[src].push_back(dest);
    indegree[dest]++;
  }

  const auto sorted = topological_sort(directed_graph, indegree);

  for (const auto mem : sorted) {
    cout << mem << " ";
  }
  cout << "\n";
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
