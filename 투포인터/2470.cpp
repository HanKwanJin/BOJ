#include<iostream>
#include<algorithm>
using namespace std;
int n; //max 2e9
int a[100004];
int ans[3];
int ret = 2e9;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	int st = 1, en = n;
	while(st < en){
		int v = a[st] + a[en];
		if(abs(v) < ret){
			ret = abs(v);
			ans[1] = a[st];
			ans[2] = a[en];
		}
		if(v < 0) st++;
		else en--;
	}
	cout << ans[1] << ' ' << ans[2];
	return 0;
}
