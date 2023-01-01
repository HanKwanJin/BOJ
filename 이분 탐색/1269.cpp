#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n,m;
int ret;
set<int> a;
set<int> b;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		a.insert(x);
	}
	for(int i=0; i<m; i++){
		int x;
		cin >> x;
		b.insert(x);
		if(a.find(x) == a.end()){
			ret++;
		}
	}
	for(auto e: a){
		if(b.find(e) == b.end()){
			ret++;
		}
	}
	cout << ret;
	return 0;
}
