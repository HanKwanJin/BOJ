#include<iostream>
using namespace std;
int n,m;
int ret;
int board1[104][104];
int board2[104][104];

void func(int board[104][104]){
	for(int i=0; i<n; i++){
		int cnt = 1; //발견되면 최소 1개 
		int j = 0;
		for(j = 0; j < n-1; j++){
			if(board[i][j] == board[i][j+1]) cnt++;
			else if(board[i][j] + 1 == board[i][j+1] && cnt >= m) cnt = 1;
			else if(board[i][j] - 1 == board[i][j+1] && cnt >= 0) cnt = -m + 1;
			else break;
		}
		if(j == n-1 && cnt >= 0) ret++;
	}
	return;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> board1[i][j];
			board2[j][i] = board1[i][j];
		}
	} 
	func(board1);
	func(board2);
	cout << ret;
	return 0;
}
