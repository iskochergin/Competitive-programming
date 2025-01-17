#include <bits/stdc++.h>

using namespace std;
const int INF = LLONG_MAX;

vector<int> pref_function(string &s) {
    int n = s.size();
    vector<int> p(n);

    for (int i = 1; i < n; i++) {
        int cur = p[i - 1];

        while (cur > 0 && s[i] != s[cur]) {
            cur = p[cur - 1];
        }

        if (s[i] == s[cur]) {
            p[i] = cur + 1;
        }
    }

    return p;
}

vector<int> z_function(string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (z[i] + i < n && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }

        if (z[i] + i - 1 > r) {
            r = z[i] + i - 1;
            l = i;
        }
    }

    return z;
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

unsigned long long get_hash(int l, int r, vi &h) {
    return sub(h[r], mul(h[l], p[r - l]));
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    p.resize(n + 1);
    vi h();

    h[0] = 0;
    p[0] = 1;

    for (int i = 0; i < n; ++i) {
        h[i + 1] = add(mul(h[i], K), T[i]);
        p[i + 1] = mul(p[i], K);
    }
}

