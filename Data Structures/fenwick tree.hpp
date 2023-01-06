class FENWICK{
	public:
		FENWICK(int &_sz) : sz(_sz){
			fenwick.assign(sz+1, 0);
		}
		void update(int &pos, int &val){
			for(; pos < sz; pos += (pos & -pos)){
				fenwick[pos] += val;
			}
		}
		int sum(int &pos){
			int ret = 0;
			for(; pos; pos -= (pos & -pos)){
				ret += fenwick[pos];
			}
			return ret;
		}
		int query(int &l, int &r){
			return sum(r) - sum(l-1);
		}
	private:
		int sz;
		vector<int> fenwick;
};
