#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int cnt;
queue<int> q;
int root;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> v[n];
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(x == -1){
			q.push(i);
			root = i;
		}
		else{
			v[x].push_back(i);
		}
	}
	int rn;
	cin >> rn;
	if(rn == root){
		cout << 0;
		return 0;
	}
	if(n == 2){
		cout << 1;
		return 0;
	}
	v[rn].clear();
	for(int i=0; i<n; i++){
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == rn) v[i].erase(v[i].begin()+j);
		}
	}
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int j=0; j < v[cur].size(); j++){
			cnt += (v[v[cur][j]].size() == 0);
			q.push(v[cur][j]);
		}
	}
	cout << cnt;
	return 0;
}
