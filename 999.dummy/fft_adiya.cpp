#include<bits/stdc++.h>

#define cd complex<double>
using namespace std;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    long long n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (long long i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (long long i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
vector<long long> multiply(vector<long long> const& a, vector<long long> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    long long n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (long long i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<long long> result(n);
    for (long long i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}