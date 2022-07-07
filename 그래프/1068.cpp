#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int cnt;
int rn;
queue<int> q;
int root;
vector<int> v[54];
bool vst[54];

int dfs(int here){
	int ret = 0;
	int child = 0;
	for(int there: v[here]){
		if(there == rn) continue;
		ret += dfs(there);
		child++;
	}
	if(child == 0) return 1;
	return ret;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(x == -1) root = i;
		else v[x].push_back(i);
	}
	cin >> rn;
	if(rn == root){
		cout << 0;
		return 0;
	}
	cout << dfs(root);
	
	return 0;
}
