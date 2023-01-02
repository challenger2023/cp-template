vector<int> LIS(vector<int>& v){
	vector<int> ans = {v[0]};
	int sz = v.size();
	for(int i:v){
		if(i > ans.back()) ans.push_back(i);
		else{
			int ptr = lower_bound(ans.begin(),ans.end(),i) - ans.begin();
			ans[ptr] = i;
		}
	}
	return ans;
}
