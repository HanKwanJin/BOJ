#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;
int t,n;
vector<string> v;
set<string> s;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		v.clear();
		s.clear();
		bool flag = false;
		for(int i=0; i<n; i++){
			string a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		for(int i=0; i < n-1; i++){
			int vs = v[i].size();
			if(v[i] == v[i+1].substr(0, vs)){
				flag = true;
				break;
			}
		}
		if(flag) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	return 0;
}
