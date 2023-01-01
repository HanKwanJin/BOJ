#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
ll d[10004];

bool chk(ll mid){
	ll tmp = m;
	for(int i=0; i<m; i++){
		tmp += mid / d[i];
	}
	return tmp >= n;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> d[i];
	}
	
	if(n <= m){
		cout << n;
		return 0;
	}
	
	ll st = 0, en = 60000000000;
	ll mid, ret = 1e18;
	while(st <= en){
		mid = (st + en) / 2;
		if(chk(mid)){
			ret = mid;
			en = mid - 1;
		}else st = mid + 1;
	}
	
	ll tmp = m;
	for(int i=0; i<m; i++) tmp += (ret - 1) / d[i];
	for(int i=0; i<m; i++){
		if(ret % d[i] == 0) tmp++;
		if(tmp == n){
			cout << i + 1;
			return 0;
		}
	}
}
