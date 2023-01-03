#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int M1 = 998244353, M2 = 1e9+7, mxN = 3e5+5;
int t = 1, f1[mxN] = {1, 1}, f2[mxN] = {1, 1};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
bool isprime(int K) {
    if (!(K % 2)) return (K == 2);
    for (int i = 3; i * i <= K; i += 2) if (!(K % i)) return false;
    return true;
}
int bm(int B, int P, int M = M2) {
    if (!P) return 1ll;
    int K = bm(B, P >> 1, M); (K *= K) %= M;
    if (P & 1ll) (K *= B) %= M; return K;
}
int inv(int B, int M = M2) {
    return bm(B, M-2, M);
}
int ncr(int N, int R, int M = M2) {
    return (((f1[N] * f2[R]) % M) * f2[N-R]) % M;
}
void fac(int M = M2) {
    for (int i = 2; i < mxN; i++) f1[i] = (f1[i-1] * i) % M;
    f2[mxN-1] = inv(f1[mxN-1], M);
    for (int i = mxN-1; i > 2; i--) f2[i-1] = (f2[i] * i) % M;
}
void solve() {
    
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for (int ti = 1; ti <= t; ti++) solve();
}
