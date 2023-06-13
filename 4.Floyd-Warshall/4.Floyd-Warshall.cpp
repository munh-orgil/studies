#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 7;

int main() {
    freopen("4.Floyd-Warshall.in", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector < vector < int > > path[n];
    vector < vector < int > > graph(n, vector < int > (n, MAX));
    for(int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--; v--;
        path[u].push_back({cost, v});
        path[v].push_back({cost, u});

        graph[u][v] = cost;
        graph[v][u] = cost;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                graph[i][j] = min(graph[i][j], (graph[i][k] + graph[k][j]));
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}