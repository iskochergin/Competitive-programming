#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
// #include <debug.h>

#pragma GCC optimize("O3")
#define int long long
#define ff first
#define ss second
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define change(a, n) a.clear(); a.resize(n);
#define END cout << '\n'; exit(0);
#define inpa(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define change(a, n) a.clear(); a.resize(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

}
