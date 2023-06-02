#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
constexpr i64 INF = 1E18;
 
void dijkstra(i64 src, vector<i64>& d, vector<vector<pii>>& g) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  d[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    i64 u = pq.top().second;
    i64 d_u = pq.top().first;
    pq.pop();
    if (d_u != d[u]) {
      continue;
    }
    for (auto [v, w] : g[u]) {
      if (d[v] > d[u] + w) {
        pq.push({d[v] = d[u] + w, v});
      }
    }
  }
}