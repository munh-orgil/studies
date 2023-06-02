#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using pii = pair<i64, i64>;
 
#define debug(...) cerr << "[" #__VA_ARGS__ " = " << __VA_ARGS__ << "]"
#define sz(v) (int) v.size()
#define all(v) begin(v), end(v)
#define lc(i) i << 1
#define rc(i) i << 1 | 1
#define INF 1e18
 
 
int main() {
  cin.tie(0)->sync_with_stdio(false);
 
  int n, m;
  cin >> n >> m;
  vector<vector<i64>> g(n), gR(n);
  vector<bool> vis(n), visR(n);
  vector<tuple<i64, i64, i64>> edges;
  for (int i = 0; i < m; i++) {
    i64 u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges.emplace_back(u, v, -w);
    g[u].emplace_back(v);
    gR[v].emplace_back(u);
  }
  function<void(int)> dfs1 = [&](i64 u) {
    if (vis[u]) {
      return;
    }
    vis[u] = true;
    for (i64 v : g[u]) {
      dfs1(v);
    }
  };
  function<void(int)> dfs2 = [&](i64 u) {
    if (visR[u]) {
      return;
    }
    visR[u] = true;
    for (i64 v : gR[u]) {
      dfs2(v);
    }
  };
  dfs1(0);
  dfs2(n - 1);
  vector<i64> d(n, INF);
  d[0] = 0;
  bool changed = true;
  for (int i = 0; i < n && changed; i++) {
    changed = false;
    for (auto [u, v, w] : edges) {
      if (d[u] < INF) {
        if (d[v] > d[u] + w) {
          d[v] = d[u] + w;
          changed = true;
          if (i == n - 1 && vis[v] && visR[v]) {
            cout << -1 << '\n';
            return 0;
          }
        }
      }
    }
  }
  cout << -d[n - 1] << '\n';
  return 0;
}