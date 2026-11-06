#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 0
#endif
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define all(x) begin(x), end(x)
#define F first
#define S second
#define pb push_back

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(a, b) (rng() % ((b) - (a) + 1) + (a))

template<class T> inline T& ckmin(T& a, const T& b) { if(b < a) a = b; return a; }
template<class T> inline T& ckmax(T& a, const T& b) { if(a < b) a = b; return a; }

template<typename T> vector<T> gen_vec(T L, T R, int sz) {
    vector<T> res(sz);
    for (int i = 0; i < sz; ++i) {
        if constexpr (is_integral_v<T>) {
            res[i] = rand(L, R);
        } else if constexpr (is_floating_point_v<T>) {
            // Generate a random floating point value in [L, R]
            res[i] = L + (R - L) * (static_cast<T>(rng()) / static_cast<T>(rng.max()));
        }
    }
    return res;
}

void print_vec(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " \n"[i == a.size() - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
