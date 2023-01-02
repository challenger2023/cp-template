class mint{
	// https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp
	public:
		using Type = typename decay<decltype(T::n)>::type;
		
		mint() : n(0ll){}
		template <typename T>
		mint(const T& m) : n(fix(m)){}
		
		template <typename T>
		static Type fix(const T& k){
			Type V;
			if(-MOD() <= k && x < MOD()) V = (Type) k;
			else V = (Type) (k % MOD());
			if(V < 0ll) V += MOD();
			return V;
		}
		
		mint operator+(const mint &a, const mint &b){
			return (a + b) % MOD;
		}
	private:
		long long n;
		static const long long MOD = 1000000007;
};
