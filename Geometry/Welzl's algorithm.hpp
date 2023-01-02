#include <bits/stdc++.h>
using namespace std;

// random number generator
mt19937_64 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

class WELZL{
    private:
        // global variables
        struct Point{
            long double x, y;
        };
        struct Circle{
            Point pt;
            long double r;
        };
        Circle ans;
        
    public:
        // initialize
        WELZL(vector<pair<long double, long double>>& v){
            int n = v.size();
            vector<Point> points;
            for (pair<long double, long double>& p:v) {
                points.push_back({p.first, p.second});
            }
            random_shuffle(points.begin(), points.end());
            ans = Welzl(points, {}, n);
        }
        
        // return the circle
        pair<pair<long double, long double>, long double> get_Answer() {
            return {{ans.pt.x, ans.pt.y}, ans.r};
        }
        
        // distance between two points
        long double find_Distance(Point& a, Point& b) {
            return sqrt(abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y));
        }
        
        // check if point is in circle
        bool inside_Circle(Point& p, Circle& c) {
            return (find_Distance(p, c.pt) <= c.r);
        }
        
        // build circle using up to three points
        Circle build_Circle(vector<Point>& points) {
            if (points.empty()) {
                return {{0.0, 0.0}, 0.0};
            } else if (points.size() == 1) {
                return {points[0], 0.0};
            } else if (points.size() == 2) {
                Point midpoint = {(points[0].x + points[1].x) / 2.0, (points[0].y + points[1].y) / 2.0};
                long double distance = find_Distance(points[0], points[1]) / 2.0;
                return {midpoint, distance};
            } else {
                long double a = points[1].x - points[0].x, 
                            b = points[1].y - points[0].y, 
                            c = points[2].x - points[0].x, 
                            d = points[2].y - points[0].y;
                long double B = a * a + b * b, 
                            C = c * c + d * d, 
                            D = a * d - b * c;
                Point position = {(d * B - b * C) / (2.0 * D), (a * C - c * B) / (2.0 * D)};
                position.x += points[0].x, position.y += points[0].y;
                long double distance = find_Distance(position, points[0]);
                return {position, distance};
            }
        }
        
        // Welzl's algorithm
        Circle Welzl(vector<Point>& points, vector<Point> edge, int n) {
            if (!n || edge.size() == 3) {
                return build_Circle(edge);
            }
            int ptr = rnd(0, n-1);
            Point p = points[ptr];
            swap(points[ptr], points[n-1]);
            Circle c = Welzl(points, edge, n-1);
            if (inside_Circle(p, c)) {
                return c;
            }
            edge.push_back(p);
            return Welzl(points, edge, n-1);
        }
};

