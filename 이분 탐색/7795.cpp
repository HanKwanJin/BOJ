#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,m;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		vector<int> a;
		vector<int> b;
		cin >> n >> m;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		for(int i=0; i<m; i++){
			int x;
			cin >> x;
			b.push_back(x);
		}
		int ret = 0;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int i=0; i<n; i++){
			auto pos = lower_bound(b.begin(), b.end(), a[i]);
			ret += pos - b.begin();
		}
		cout << ret << '\n';
	}
}
