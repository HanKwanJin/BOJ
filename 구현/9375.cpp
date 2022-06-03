#include<iostream>
#include<string>
#include<map>
typedef long long ll;
using namespace std;
string k,v;
int t,n,sum;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		map<string, int> m;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> v >> k;
			m[k]++;
		}
		ll ret = 1;
		for(auto e: m){
			ret *= (ll)(e.second + 1);
		}
		ret--;
		cout << ret << '\n'; 
	}
	return 0;
}
