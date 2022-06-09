#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define Y first
#define X second
using namespace std;
int n,m,k;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool vst[104][104];
vector<int> v;
queue<pair<int,int>> q;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	while(k--){
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i=y1; i < y2; i++){
			for(int j=x1; j<x2; j++){
				vst[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(vst[i][j]) continue;
			vst[i][j] = 1;
			cnt++;
			q.push({i,j});
			int area = 1;
			while(!q.empty()){
				auto cur = q.front(); q.pop();
				for(int i=0; i<4; i++){
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
					if(vst[ny][nx]) continue;
					q.push({ny,nx});
					vst[ny][nx] = 1;
					area++;
				}
			}
			v.push_back(area);
		}
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for(auto a: v){
		cout << a << ' ';
	}
	return 0;
}
