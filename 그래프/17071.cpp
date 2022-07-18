#include<iostream>
#include<queue>
using namespace std;
int n,k;
int a = 1;
int d[2][500001]; //0 ¼öºó 1 µ¿»ý 
queue<int> q;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	if(n == k){
		cout << 0;
		return 0;
	}
	d[0][n] = 1;
	q.push(n);
	bool chk = false;
	while(1){
		k += a;
		if(k > 500000) break;
		if(d[a%2][k]) {
			chk = true;
			break;
		}
		int qs = q.size();
		while(qs--){
			auto cur = q.front(); q.pop();
			for(int nx: {cur*2, cur-1, cur+1}){
				if(nx < 0 || nx > 500000) continue;
				if(d[a%2][nx]) continue;
				d[a%2][nx] = 1;
				if(nx == k){
					chk = true;
					break;
				}
				q.push(nx);
			}
			if(chk) break;
		}
		if(chk) break;
		a++; 
	}
	if(chk){
		cout << a;
	}else{
		cout << -1;
	}
	return 0;
}
