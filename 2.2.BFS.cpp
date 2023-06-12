#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("2.TreeSearch.in", "r", stdin);
    
    int n, m;
    cin >> n >> m;
    vector < int > path[n];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        path[u].push_back(v);
        path[v].push_back(u);
    }

    int st, fn;
    queue < int > q;
    vector < int > par(n, -1);
    cin >> st >> fn;
    st--; fn--;
    q.push(st);
    par[st] = st;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < path[x].size(); i++) {
            int to = path[x][i];
            if(par[to] == -1) {
                par[to] = x;
                q.push(to);
            }
        }
    }
    
    int tail = fn;
    vector < int > ans;
    while(tail != st) {
        ans.push_back(tail + 1);
        tail = par[tail];
    }
    ans.push_back(st + 1);
    cout << ans.size() << endl;
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;
}