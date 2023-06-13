#include <bits/stdc++.h>
using namespace std;
 
using f64 = long double;
using i64 = long long;
using P = complex<f64>;
#define X real()
#define Y imag()

int orientation(P p1, P p2) {
    i64 o = (conj(p1) * p2).Y;
    if (o == 0) {
        return 0;
    }
        // o == 0 TOUCH
        // o == 1 LEFT
        // o == -1 RIGHT
    return (o > 0 ? 1 : -1);
}
 
int point_location(P p1, P p2, P p) {
    return orientation((p - p1), (p - p2));
}
 
bool on_segment(P p1, P p2, P p) {
    bool exist = true;
    exist &= (p.X >= min(p1.X, p2.X));
    exist &= (p.X <= max(p1.X, p2.X));
    exist &= (p.Y >= min(p1.Y, p2.Y));
    exist &= (p.Y <= max(p1.Y, p2.Y));
    return exist;
}
 
bool intersection(vector<P>& p) {
    P p1 = p[0], p2 = p[1], p3 = p[2], p4 = p[3];
    int o1 = point_location(p1, p2, p3);
    int o2 = point_location(p1, p2, p4);
    int o3 = point_location(p3, p4, p1);
    int o4 = point_location(p3, p4, p2);
 
    if (o1 != o2 && o3 != o4) {
        return true;
    }
    bool ok = false;
    ok |= (o1 == 0 && on_segment(p1, p2, p3));
    ok |= (o2 == 0 && on_segment(p1, p2, p4));
    ok |= (o3 == 0 && on_segment(p3, p4, p1));
    ok |= (o4 == 0 && on_segment(p3, p4, p2));
    return ok;
}

i64 cross_product(P p1, P p2) {
    return (i64) (conj(p1) * p2).Y;
}
 
i64 polygon_area(vector<P>& p, int n) {
    i64 area = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        area += cross_product(p[j], p[i]);
        j = i;
    }
 
    return abs(area);
}