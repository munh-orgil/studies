#include<bits/stdc++.h>

#define _ << " " <<

using namespace std;

class VEB {
public:
    int mn, mx;
    int universeSize;
    VEB* summary;
    vector<VEB*> cluster;
    bool isEmpty;

    VEB(int size) {
        universeSize = size;
        isEmpty = true;
        mn = 1e9;
        mx = 0;
        if (size > 2) {
            int root = ceil(sqrt(size));
            summary = new VEB(root);
            cluster = vector<VEB*> (root);
            for (int i = 0; i < root; i++) {
                cluster[i] = new VEB(root);
            }
        }
    }
    void insert(int x) {
        mx = max(mx, x);
        if (isEmpty) {
            mn = x;
            isEmpty = false;
            return;
        }
        if (x < mn) {
            swap(x, mn);
        }
        int rootSize = ceil(sqrt(universeSize));
        int c = x / rootSize;
        int i = x % rootSize;
        if (cluster[c]->isEmpty) {
            summary->insert(c);
        }
        cluster[c]->insert(i);
    }
    int predecessor(int x) {
        // cout << x << endl;
        if (x > mx) {
            return mx;
        }
        if (x <= mn) {
            return -1;
        }
        // if (x < mn) {
        //     return -1;
        // }
        int rootSize = ceil(sqrt(universeSize));
        int c = x / rootSize;
        int i = x % rootSize;
        if (cluster[c]->isEmpty || x <= cluster[c]->mn) {
            if (c < summary->mn) {
                return mn;
            }
            int maxExisting = summary->predecessor(c);
            return cluster[maxExisting]->mx;
        }
        else {
            return cluster[c]->predecessor(i);
        }
        return -1;
    }
};

int main() {
    VEB *veb = new VEB(10);
    // veb->insert(1);
    // cout << veb->mn << " " << veb->mx << endl;
    // veb->insert(2);
    // cout << veb->mn << " " << veb->mx << endl;
    veb->insert(6);
    // cout << veb->mn << " " << veb->mx << endl;
    veb->insert(8);
    // cout << veb->mn << " " << veb->mx << endl;
    veb->insert(9);
    // cout << veb->mn << " " << veb->mx << endl;

    // for (auto c : veb->cluster) {
    //     cout << c->mn << endl;
    // }
    // cout << veb->predecessor(9);
    for (int i = 4; i < 10; i++) {
        cout << i << " " << veb->predecessor(i) << endl;
    }
}