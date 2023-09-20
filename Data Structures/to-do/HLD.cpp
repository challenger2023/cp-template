#include <bits/stdc++.h>
using namespace std;
class HLD {
    public:
        HLD(vector<vector<int>> const& adj) {
            int n = adj.size();
            parent.resize(n);
            depth.resize(n);
            heavy.resize(n, -1);
            head.resize(n);
            pos.resize(n);
            cur_pos = 0;
            dfs(0, adj);
            decompose(0, 0, adj);
        }
        int dfs(int v, vector<vector<int>> const& adj) {
            int sz = 1;
            int mx_c_sz = 0;
            for (int c : adj[v]) {
                if (c == parent[v]) continue;
                parent[c] = v, depth[c] = depth[v] + 1;
                int c_sz = dfs(c, adj);
                sz += c_sz;
                if (c_sz > mx_c_sz) mx_c_sz = c_sz, heavy[v] = c;
            }
            return sz;
        }
        void decompose(int v, int h, vector<vector<int>> const& adj) {
            head[v] = h, pos[v] = cur_pos++;
            if (heavy[v] != -1) decompose(heavy[v], h, adj);
            for (int c:adj[v]) if (c != parent[v] && c != heavy[v]) decompose(c, c, adj);
        }
        int query(int a, int b) {
            int ret = 0;
            for (; head[a] != head[b]; b = parent[head[b]]) {
                if (depth[head[a]] > depth[head[b]]) swap(a, b);
                // add lazy segtree above
                int cur_heavy_path_mx = segment_tree_query(pos[head[b]], pos[b]);
                ret = max(ret, cur_heavy_path_mx);
            }
            if (depth[a] > depth[b]) swap(a, b);
            int last_heavy_path_mx = segment_tree_query(pos[a], pos[b]);
            ret = max(ret, last_heavy_path_mx);
            return ret;
        }
    private:
        vector<int> parent, depth, heavy, head, pos;
        int cur_pos;
};
