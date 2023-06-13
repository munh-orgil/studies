#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("3.Dijkstra.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    vector < vector < int > > path[n];
    for(int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--; v--;
        path[u].push_back({cost, v});
        path[v].push_back({cost, u});
    }
    priority_queue<vector<int>, vector< vector<int> >, greater< vector<int> > > pq;
    vector < int > dist(n, int(INFINITY)), par(n);
    int st, fn;
    cin >> st >> fn;
    st--; fn--;
    dist[st] = 0;
    pq.push({0, st});
    while(!pq.empty()) {
        vector <int> x = pq.top();
        pq.pop();

        for(int i = 0; i < path[x[1]].size(); i++) {
            int to = path[x[1]][i][1];
            int cost = path[x[1]][i][0];
            if(dist[to] > x[0] + cost) {
                par[to] = x[1];
                dist[to] = x[0] + cost;
                pq.push({dist[to], to});
            }
        }
    }

    cout << dist[fn] << endl;
    vector < int > ans;
    int pos = fn;
    ans.push_back(fn + 1);
    while(pos != st) {
        pos = par[pos];
        ans.push_back(pos + 1);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}