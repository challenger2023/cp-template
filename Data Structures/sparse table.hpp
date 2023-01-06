class SPARSE{
	public:
		SPARSE(int _sz) : sz(_sz){
			depth = (int) ceil(log2(sz));
			st.resize(depth+1);
			st[0].resize(sz);
		}
		int fun(int a, int b){
			return max(a, b);
		}
		void update(int pos, int val){
			st[0][pos] = val;
		}
		void build(){
			for(int i = 1; i <= depth; i++){
				for(int j = 0; j + (1 << i) <= sz; j++){
					st[i][j] = fun(st[i-1][j], st[i-1][j + (1 << (i-1))]);
				}
			}
		}
		int query(int l, int r){
			if(l == r) return st[0][l];
			int k = (int) floor(log2(r-l));
			return max(st[k][l], st[k][r - (1 << k) + 1])
		}
	private:
		int sz, depth;
		vector<vector<int>> st;
};
