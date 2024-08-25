#include<bits/stdc++.h>

using namespace std;

struct BIT {
  int n;
  vector<int> bit;
 
  BIT(int len) : n(len + 1), bit(len + 1, 0) {}
 
  void add(int i, int v) {
    for (++i; i < n; i += i & -i) {
      bit[i] += v;
    }
  }
 
  int get(int i) {
    int res = 0;
    for (++i; i > 0; i -= i & -i) {
      res += bit[i];
    }
    return res;
  }
};