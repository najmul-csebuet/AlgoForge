#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pb push_back
#define eb emplace_back
#define fill(v, c) memset(v, c, sizeof(v))

#define var auto
#define endl "\n"
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

inline void printArray(vector<int> n, string separator = " ") {
  if (n.size() == 0) return;
  rep(i, 0, n.size() - 1) cout << n[i] << separator;
  cout << n[n.size() - 1] << endl;
}

struct State {
  int parent = -1, distance = INT_MAX;
  bool visited = false;
};

void solve() {
  // read inputs
  int v, e;
  cin >> v >> e;
  int graph[v + 1][v + 1];
  rep(i, 1, v + 1) rep(j, 1, v + 1) graph[i][j] = 0;
  while (e--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u][v] = w;
    graph[v][u] = w;
  }

  vector<State> state(v + 1);
  state[1].distance = 0;
  state[1].visited = true;

  priority_queue<int> q;
  q.emplace(1);

  while (q.empty() == false) {
    int cur = q.top();
    q.pop();
    rep(i, 1, v + 1) {
      if (graph[cur][i] == 0) continue;
      if (state[i].visited == true) continue;
      if (state[cur].distance + graph[cur][i] >= state[i].distance) continue;
      state[i].distance = state[cur].distance + graph[cur][i];
      state[i].visited = true;
      state[i].parent = cur;
      q.emplace(i);
    }
  }

  vector<int> path = {v};
  int t = v;
  while (state[t].parent != -1) {
    path.eb(state[t].parent);
    t = state[t].parent;
  }

  reverse(all(path));
  printArray(path);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testCount = 1;
  // testCount = io.nextInt();
  while (testCount > 0) {
    solve();
    --testCount;
  }
  return 0;
}