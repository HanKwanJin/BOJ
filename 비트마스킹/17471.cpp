#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
const int INF = 987654321;
int n, ret = INF, a[14], comp[14];
bool vst[14];
vector<int> v[14];
pair<int,int> go(int cur, int value){
	vst[cur] = 1;
	pair<int,int> ret = {1, a[cur]};
	for(auto e: v[cur]){
		if(comp[e] != value) continue;
		if(vst[e]) continue;
		pair<int,int> tmp = go(e, value);
		ret.first += tmp.first;
		ret.second += tmp.second;
	}
	return ret;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++){
		int cnt;
		cin >> cnt;
		for(int j=1; j<=cnt; j++){
			int x;
			cin >> x;
			v[i].push_back(x);
			v[x].push_back(i);
		}
	}
	for(int i=1; i < (1 << n) - 1; i++){
		fill(comp,comp + 11, 0);
		fill(vst, vst + 11, 0);
		int idx1 = -1, idx2 = -1;
		for(int j=0; j<n; j++){
			if(i & (1 << j)) {
				comp[j+1] = 1; idx1 = j + 1;
			}else idx2 = j + 1;
		}
		pair<int,int> comp1 = go(idx1, 1);
		pair<int,int> comp2 = go(idx2, 0);
		if(comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));
	}
	cout << (ret == INF ? -1 : ret);
	return 0;
}
