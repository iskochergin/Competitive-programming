// This code is made by Ivan Kochergin
// Hope that you (testing system) will like it ❤
#define _GLIBCXX_DEBUG // Universal thing to get description of errors in program, that C++ just doesn't give
#include <bits/stdc++.h>
#include <debug.h> // Visit debug.h in the same folder to get the description of these helpful script (comment before uploading to the testing system)

#define int long long 
#define ff first
#define ss second
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define change(a, n) a.clear(); a.resize(n); // clears and resizes the array a with size n
#define END cout << '\n'; exit(0); // Convenient to finish your program with END
#define inpa(a, n) for (int i = 0; i < n; i++) cin >> a[i]; // Gets the array a with length n from std::cin
// Gets the adjacency list of an UNDIRECTED UNWEIGHTED graph to vector<vector<int>> g, there are m edges in the input data
#define inp_gn(g, m) for (int i = 0; i < m; i++) {int u, v; cin >> u >> v; g[u].push_back(v); g[v].push_back(u);}
// Gets the adjacency list of an DIRECTED UNWEIGHTED graph to vector<vector<int>> g, there are m edges in the input data
#define inp_go(g, m) for (int i = 0; i < m; i++) {int u, v; cin >> u >> v; g[u].push_back(v);}
// Gets the adjacency list of an UNDIRECTED WEIGHTED graph to vector<vector<int>> g, there are m edges in the input data
#define inp_gwn(g, m) for (int i = 0; i < m; i++) {int u, v, w; cin >> u >> v >> w; g[u].emplace_back(v, w); g[v].emplace_back(u, w);}
// Gets the adjacency list of an DIRECTED WEIGHTED graph to vector<vector<int>> g, there are m edges in the input data
#define inp_gwo(g, m) for (int i = 0; i < m; i++) {int u, v, w; cin >> u >> v >> w; g[u].emplace_back(v, w);}
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using str = string;
const int INF = 1e18 + 1;
const int MOD = 1e9 + 7;

// Prints an array a (inspired by Python) with sep=s and end=e 
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

// The sum modulo
int add(int a, int b) {
    if (a + b >= MOD) {
        return a + b - MOD;
    }
    return a + b;
}

// The difference modulo
int sub(int a, int b) {
    if (a - b < 0) {
        return a - b + MOD;
    }
    return a - b;
}

// The multiplication modulo
int mul(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

// Your main program code
void test() {
    
}

signed main() {
    // Input/output accelerator
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // The helpful structure for Codeforces rounds with multiple tests
    // To enable it you only need to uncomment "cin >> TT". Them your program (void test()) will be executed for TT times
    int TT;
    TT = 1;
//    cin >> TT;
    while (TT--) {
        test();
    }
}
