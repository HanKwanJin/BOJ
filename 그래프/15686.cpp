#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#define X second
#define Y first
using namespace std;
int n,m,sz;
int board[54][54];
bool vst[54][54];
vector<pair<int,int>> c;
vector<pair<int,int>> h;
int ans = 987654321;

void func(int k){
	if(k == sz){
		//거리 계산 로직
		int ret = 0;
		for(auto hh: h){
			int tmp = 987654321;
			for(auto cc: c){
				if(board[cc.Y][cc.X] == 2){
					tmp = min(tmp,(abs(cc.X - hh.X) + abs(cc.Y - hh.Y)));
				}
			}
			ret += tmp;
		}
		ans = min(ans, ret);
		return;
	}
	for(int i=0; i<c.size(); i++){
		if(!vst[c[i].Y][c[i].X]){
			vst[c[i].Y][c[i].X] = 1;
			board[c[i].Y][c[i].X] = 0;
			func(k+1);
			vst[c[i].Y][c[i].X] = 0;
			board[c[i].Y][c[i].X] = 2; 
		}
	}
} 
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board[i][j];
			if(board[i][j] == 1){
				h.push_back({i,j});
			}
			if(board[i][j] == 2){
				c.push_back({i,j});				
			}
		}
	}
	sz = c.size() - m; //없애야 하는 치킨집의 수
	func(0);
	cout << ans;
	return 0;
}
