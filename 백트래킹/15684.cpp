#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 987654321;
int n,m,h,a,b,ret = INF;
bool vst[32][12];

bool chk(){
	for(int i=1; i<=n; i++){
		int st = i;
		for(int j=1; j<=h; j++){
			if(vst[j][st]) st++;
			else if(vst[j][st-1]) st--;
		}
		if(st != i) return false;
	}
	return true;
}

void go(int here, int cnt){
	if(cnt > 3 || cnt >= ret) return;
	if(chk()){
		ret = min(ret, cnt);
		return;
	}
	for(int i=here; i<=h; i++){
		for(int j=1; j<=n; j++){
			if(vst[i][j] || vst[i][j-1] || vst[i][j+1]) continue;
			vst[i][j] = 1;
			go(i, cnt+1);
			vst[i][j] = 0;
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> h;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		vst[a][b] = 1;
	}
	go(1,0);
	cout << (ret == INF ? -1 : ret);
	return 0;
	return 0;
}
