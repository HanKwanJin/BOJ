#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int t,n;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		int ret1 = 0, ret2 = 0;
		int cnt = 0;
		cin >> n;
		for(int i=2; i <=n; i*=2){
			cnt = n / i;
			ret1 += cnt;
		}
		for(int i=5; i<=n; i*=5){
			cnt = n / i;
			ret2 += cnt;
		}
		cout << min(ret1, ret2) << '\n';
	}
	return 0;
}
