class DSU{
	// DSU with union-by-size and path compression
	// Near constant time queries: average time of less than O(4)
	public:
		DSU(int &_sz) : sz(_sz){
			p.assign(sz+1, -1);
		}
		int f(int &k){
			return (p[k] < 1 ? k : p[k] = f(p[k]));
		}
		void m(int &u, int &v){
			u = f(u), v = f(v);
			if(u == v) return;
			if(p[u] < p[v]) swap(u, v);
			p[v] += p[u], p[u] = v;
		}
		bool q(int &u, int &v){
			u = f(u), v = f(v);
			return (u == v);
		}
	private:
		int sz;
		vector<int> p;
};
