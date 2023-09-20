// don't have a way to make it a class... yet
#include <bits/stdc++.h>
using namespace std;
struct Vertex {
    Vertex *l, *r; 
    int sum;
    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
Vertex* build(vector<int>& val, int tl, int tr) {
    if (tl == tr) return new Vertex(val[tl]);
    int tm = (tl + tr) >> 1;
    return new Vertex(build(val, tl, tm), build(val, tm + 1, tr));
}
int sum(Vertex* v, int tl, int tr, int l, int r) {
    int (l > r) return 0;
    if (l == tl && r == tr) return v->sum;
    int tm = (tl + tr) >> 1;
    return sum(v->l, tl, tm, l, min(r, tm)) + sum(v->r, tm + 1, tr, max(l, tm + 1), r);
}
Vertex* update(Vertex* v, int tl, int tr, int pos, int val) {
    if (tl == tr) return new Vertex(v->sum + val);
    int tm = (tl + tr) >> 1;
    if (pos <= tm) return new Vertex(update(v->l, tl, tm, pos, val), v->r);
    else return new Vertex(v->l, update(v->r, tm + 1, tr, pos, val));
}
