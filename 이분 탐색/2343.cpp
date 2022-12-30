#include<iostream>
#include<algorithm>
using namespace std;
int n,m,sum;
int d[100001];

bool chk(int mid){
	for(int i=0; i<n; i++){
		if(d[i] > mid) return false;
	}
	int tmp = mid;
	int cnt = 0;
	for(int i=0; i<n; i++){
		if(tmp - d[i] < 0) {
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
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> d[i];
		sum += d[i];
	}
	int st = 0, en = sum, mid;
	int ret = 987654321;
	while(st <= en){
		mid = (st + en) / 2;
		if(chk(mid)){
			ret = min(ret, mid);
			en = mid - 1;
		}else{
			st = mid + 1;
		}
	}
	cout << ret;
	return 0;
}
