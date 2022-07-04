#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<utility>
#define Y first
#define X second
using namespace std;

int h,w;
int board[101][101];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	memset(board, -1, sizeof(board));
	queue<pair<int,int>> q;
	for(int i=0; i<h; i++){
		string a;
		cin >> a;
		for(int j=0; j<w; j++){
			if(a[j] == 'c') board[i][j] = 0;
		}
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(board[i][j] == 0) q.push({i,j});
			if(board[i][j] != -1) continue;
			while(!q.empty()){
				auto cur = q.front(); q.pop();
				int nx = cur.X + 1;
				if(nx >= w || board[cur.Y][nx] != -1) continue;
				q.push({cur.Y, nx});
				board[cur.Y][nx] = board[cur.Y][cur.X] + 1;
			}
		}
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
