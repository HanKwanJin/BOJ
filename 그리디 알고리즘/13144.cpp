#include<iostream>
typedef long long ll;
using namespace std;
ll n,s,e;
ll ret;
ll a[100004], cnt[100004];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	while(e < n){
		if(!cnt[a[e]]){
			cnt[a[e]]++;
			e++;
		}else{
			ret += (e - s);
			cnt[a[s]]--;
			s++;
		}
	}
	ret += (long long)(e-s) * (e-s+1) / 2;
	cout << ret;
	return 0;
}
