#include<bits/stdc++.h>
using namespace std;
int n,c;
map<int,int> m;
map<int,int> order;
vector<pair<int,int>> v;
vector<int> a;
bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first) return order[a.second] < order[b.second];
	return a.first > b.first;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(m[x] == 0) order[x] = i + 1;
		m[x]++;
	}
	for(auto i = m.begin(); i != m.end(); i++){
		v.push_back({i->second, i->first});
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i < v.size(); i++){
		for(int j=0; j < v[i].first; j++){
			a.push_back(v[i].second);
		}
	}
	for(int e: a){
		cout << e << " ";
	}
	return 0;
}
