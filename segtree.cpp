#include<bits/stdc++.h>

using namespace std;

using i64 = long long;
#define lc(i) i << 1
#define rc(i) i << 1 | 1

struct SegmentTree {
  vector<int> tree;
  int n;
 
  SegmentTree(int _n) {
    this->n = _n;
    tree.assign(n << 2, INT_MAX);
  }
  
  void modify(int pos, int val) {
    modify(1, 1, n, pos, val);
  }
 
  void modify(int si, int ss, int se, int pos, int val) {
    if (ss == se) {
      tree[si] = val;
      return;
    }
    int sm = (ss + se) >> 1;
    pos <= sm ? modify(lc(si), ss, sm, pos, val)
              : modify(rc(si), sm + 1, se, pos, val);
    tree[si] = min(tree[lc(si)], tree[rc(si)]);
  }
 
  int query(int qs, int qe) {
    return query(1, 1, n, qs, qe);
  }
 
  int query(int si, int ss, int se, int qs, int qe) {
    if (qs > qe) {
      return INT_MAX;
    }
    if (ss == qs &&  qe == se) {
      return tree[si];
    }
    int sm = (ss + se) >> 1;
    int left = query(lc(si), ss, sm, qs, min(qe, sm));
    int right = query(rc(si), sm + 1, se, max(sm + 1, qs), qe);
    return min(left, right);
  }
};