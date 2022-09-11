#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,cnt; //1~1000
bool vst[1001];
vector<int> v[1001];

void dfs(int here){
	vst[here] = 1;
	for(auto e: v[here]){
		if(!vst[e]) dfs(e);
	}
	return;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		cin >> m;
		cnt = 0;
		for(int i=0; i<=1000; i++) v[i].clear();
		memset(vst, false, sizeof(vst));
		for(int i=0; i<m; i++){
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1; i<=n; i++){
			if(!vst[i]){
				dfs(i);
				cnt++;
			}
		}
		
		if(m == n-1 && cnt == 1) cout << "tree" << '\n';
		else cout << "graph" << '\n';
	}
	return 0;
}
