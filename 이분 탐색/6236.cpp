#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
ll d[100001];
ll sum;
bool chk(int mid){
	for(int i=0; i<n; i++){
		if(d[i] > mid) return false;
	}
	ll tmp = mid;
	ll cnt = 0;
	for(int i=0; i<n; i++){
		if(tmp - d[i] < 0){
			tmp = mid;
			cnt++;
		}
		tmp -= d[i];
	}
	cnt++;
	return cnt <= m;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i < n; i++){
		cin >> d[i];
		sum += d[i];
	}
	ll st = 0, en = sum, mid;
	ll ret = 1e18;
	while(st <= en){
		mid = (st + en) / 2;
		if(chk(mid)){
			ret = min(ret, mid);
			en = mid - 1;
		}else st = mid + 1;
	}
	cout << ret;
	return 0;
}
