#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
const int INF = 1e9;
int n;
int ret = INF;
int a[24];
string s;
int cc;
void func(int cur){
	if(cur == n + 1){	
		int sum = 0;
		for(int i=1; i<= 1 << (n-1); i*=2){
			int cnt = 0;
			for(int j=1; j<=n; j++){
				cc++;
				if(a[j] & i) cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		ret = min(ret, sum);
		return;
	}
	
	a[cur] = ~a[cur];
	func(cur + 1);
	a[cur] = ~a[cur];
	func(cur + 1);
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> s;
		int v = 1;
		for(int j=0; j<s.size(); j++){
			if(s[j] == 'T') a[i] |= v;
			v *= 2;
		}
	}
	func(1);
	cout << cc << " ----\n";
	cout << ret;
	return 0;
}
