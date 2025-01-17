#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
const double PI = atan2(1, 0) * 2;

struct Point {
    ll x, y;

    Point(ll x, ll y): x(x), y(y) {}

    Point(): x(0), y(0) {}

    ld len() const {
        return sqrt(x * x + y * y);
    }

    ll len2() const {
        return x * x + y * y;
    }
};

Point operator+(Point A, Point B) {
    return Point(A.x + B.x, A.y + B.y);
}

Point operator-(Point A, Point B) {
    return Point(A.x - B.x, A.y - B.y);
}

Point operator*(Point A, int B) {
    return Point(A.x * B, A.y * B);
}

ll operator*(Point A, Point B) {
    return A.x * B.x + A.y * B.y;
}

ll operator%(Point A, Point B) {
    return A.x * B.y - A.y * B.x;
}

ostream &operator<<(ostream &out, Point &A) {
    cout << A.x << ' ' << A.y << '\n';
    return out;
}

istream &operator>>(istream &in, Point &A) {
    cin >> A.x >> A.y;
    return in;
}

ld line(Point A, Point B, Point C) {
    auto AB = B - A;
    auto AC = C - A;
    auto BC = B - C;
    return abs(AB % AC) / BC.len();
}

ld segment(Point A, Point B, Point C) {
    auto BA = A - B;
    auto BC = C - B;
    auto CA = A - C;
    auto CB = B - C;
    if (BA * BC <= 0) {
        return BA.len();
    } else if (CB * CA <= 0) {
        return CA.len();
    } else {
        return line(A, B, C);
    }
}

int sign(ld n) {
    return (n > 0) - (n < 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}
