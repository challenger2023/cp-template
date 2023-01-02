class SEGTREE_LAZY_RANGEADD{
	public:
		SEGTREE_LAZY_RANGEADD(int _sz) : sz(_sz){
			st.assign(4*sz+1, 0);
			lazy.assign(4*sz+1, 0);
		}
		void fun(int a, int b){
			return a + b;
		}
		void push(int pos){
			if (!lazy[pos]) return;
			st[2*pos] += lazy[pos];
			lazy[2*pos] += lazy[pos];
			st[2*pos+1] += lazy[pos];
			lazy[2*pos+1] += lazy[pos];
			lazy[pos] = 0;
		}
		void pull(int pos) {
			st[pos] = fun(st[2*pos], st[2*pos+1]);
		}
		void build(vector<int>& val, int l = 1, int r = n, int pos = 1) {
			if (l == r) {
				st[pos] = val[l];
				return;
			}
			int m = (l + r) >> 1;
			build(val, l, m, 2*pos);
			build(val, m+1, r, 2*pos+1);
			pull(pos);
		}
		void update(int val, int l, int r, int pos = 1, int tl = 1, int tr = sz){
			if(l > r) return;
			if(l == tl && r == tr){
				st[pos] += val;
				lazy[pos] += val;
				return;
			}
			push(pos);
			int tm = (tl + tr) >> 1;
			update(val, l, min(tm, r), 2*pos, tl, tm);
			update(val, max(l, tm+1), r, 2*pos+1, tm+1, tr);
			pull(pos);
		}
		int query(int l, int r, int pos = 1, int tl = 1, int tr = sz){
			if(l <= tl && tr <= r) return st[pos];
			push(pos);
			int tm = (tl + tr) >> 1;
			pull(pos);
			return st[pos];
		}
	private:
		int sz;
		vector<int> st, lazy;
};
