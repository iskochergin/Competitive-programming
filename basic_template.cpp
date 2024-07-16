// This code is made by Ivan Kochergin
// Hope that you (testing system) will like it ❤
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <debug.h>

#define int long long
#define ff first
#define ss second
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define change(a, n) a.clear(); a.resize(n);
#define END cout << '\n'; exit(0);
#define inpa(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define inp_gn(g, m) for (int i = 0; i < m; i++) {int u, v; cin >> u >> v; g[u].push_back(v); g[v].push_back(u);}
#define inp_go(g, m) for (int i = 0; i < m; i++) {int u, v; cin >> u >> v; g[u].push_back(v);}
#define inp_gwn(g, m) for (int i = 0; i < m; i++) {int u, v, w; cin >> u >> v >> w; g[u].emplace_back(v, w); g[v].emplace_back(u, w);}
#define inp_gwo(g, m) for (int i = 0; i < m; i++) {int u, v, w; cin >> u >> v >> w; g[u].emplace_back(v, w);}
#define change(a, n) a.clear(); a.resize(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using str = string;
const int INF = 1e18 + 1;
const int MOD = 1e9 + 7;

template <typename T>
void printa(const T& a, str s=" ", str e="\n") {
    int cn = 0;
    for (auto i : a) {
        if (cn != (int)a.size() - 1) {
            cout << i << s;
        } else {
            cout << i;
        }
        cn++;
    }
    cout << e;
}

int add(int a, int b) {
    if (a + b >= MOD) {
        return a + b - MOD;
    }
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) {
        return a - b + MOD;
    }
    return a - b;
}

int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

void test() {
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TT;
    TT = 1;
//    cin >> TT;
    while (TT--) {
        test();
    }
}
