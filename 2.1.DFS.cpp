#include<bits/stdc++.h>

using namespace std;

vector < int > ans;

void DFS(int pos, int finish, vector< vector<int> > path, vector < int > way, vector < bool > vis) {
    if(pos == finish) {
        if(way.size() < ans.size() || ans.size() == 0) {
            ans = way;
        }
        return;
    }
    for(int i = 0; i < path[pos].size(); i++) {
        int to = path[pos][i];
        
        if(!vis[to]) {
            way.push_back(to);
            vis[to] = 1;
            DFS(to, finish, path, way, vis);
            way.pop_back();
        }
    }
}

int main() {
    freopen("2.TreeSearch.in", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector < vector < int > > path(n);
    vector < bool > vis(n);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;
    vector < int > way;
    way.push_back(start);
    vis[start] = 1;
    DFS(start, finish, path, way, vis);
    
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}