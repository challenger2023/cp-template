#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

// random number generator
mt19937_64 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// global variables
struct Point{
    ld x, y;
};
struct Circle{
    Point p;
    ld r;
};

// distance between two points
ld find_Distance(Point& a, Point& b) {
    return sqrtl(abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y));
}

// check if point is in circle
bool in_Circle(Point& pt, Circle& c) {
    return (find_Distance(pt, c.p) <= c.r);
}

// find circumcircle of up to three points
Circle find_Circumcircle(vector<Point>& edge) {
    if (edge.empty()) {
        return {{0.0, 0.0}, 0.0};
    } else if (edge.size() == 1) {
        return {edge[0], 0.0};
    } else if (edge.size() == 2) {
        return {{(edge[0].x + edge[1].x) / 2.0, (edge[0].y + edge[1].y) / 2.0}, find_Distance(edge[0], edge[1]) / 2.0};
    } else {
        ld a = edge[1].x - edge[0].x, b = edge[1].y - edge[0].y, c = edge[2].x - edge[0].x, d = edge[2].y - edge[0].y;
        ld bb = a * a + b * b, cc = c * c + d * d, dd = a * d - b * c;
        Point p = {(d * bb - b * cc) / (2.0 * dd), (a * cc - c * bb) / (2.0 * dd)};
        p.x += edge[0].x, p.y += edge[0].y;
        return {p, find_Distance(p, edge[0])};
    }
}

// Welzl's algorithm
Circle solve(vector<Point>& points, vector<Point> edge, int n) {
    if (!n || edge.size() == 3) {
        return find_Circumcircle(edge);
    }
    int ptr = rnd(0, n-1);
    Point p = points[ptr];
    swap(points[ptr], points[n-1]);
    Circle c = solve(points, edge, n-1);
    if (in_Circle(p, c)) {
        return c;
    }
    edge.push_back(p);
    return solve(points, edge, n-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    Circle ans = solve(points, {}, n);
    cout << fixed << setprecision(10) << ans.p.x << ' ' << ans.p.y << ' ' << ans.r << '\n';
}
