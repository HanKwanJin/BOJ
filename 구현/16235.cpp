#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n,m,k;
int p[104][104]; //겨울에 더 해지는 양분 
vector<int> tree[104][104];
int energy[104][104]; //현재 양분 정보 
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

void spring_summer(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int dietree = 0;
			vector<int> tmp;
			sort(tree[i][j].begin(), tree[i][j].end());
			for(auto e: tree[i][j]){
				if(energy[i][j] >= e){
					energy[i][j] -= e;
					tmp.push_back(e + 1);
				}else dietree += e / 2;
			}
			tree[i][j].clear();
			tree[i][j] = tmp;
			energy[i][j] += dietree;
		}
	}
}

void fall(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(auto e: tree[i][j]){
				if(e % 5 == 0){
					for(int dir=0; dir<8; dir++){
						int ny = i + dy[dir];
						int nx = j + dx[dir];
						if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
						tree[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

void winter(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			energy[i][j] += p[i][j];
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> p[i][j];
			energy[i][j] = 5;
		}
	}
	for(int i=1; i<=m; i++){
		int y,x,z;
		cin >> y >> x >> z;
		tree[y][x].push_back(z);
	}
	
	while(k--){
		//spring_summer
		spring_summer();
		//fall
		fall();
		//winter	
		winter();
	}
	int cnt = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(auto e: tree[i][j]){
				if(e > 0) cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
