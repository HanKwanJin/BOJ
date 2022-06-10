#include<iostream>
#include<string>
using namespace std; 

int n;
string board[65];

void func(int y, int x, int n){
	if(n == 1){
		cout << board[y][x];
		return; 
	}
	bool zero = false;
	bool one = false;
	for(int i = y; i < y + n; i++){
		for(int j = x; j < x + n; j++){
			if(board[i][j] == '1'){
				one = true;
			}else if(board[i][j] == '0'){
				zero = true;
			}
		}
	}
	if(one && !zero){
		cout << 1;
	}else if(zero && !one){
		cout << 0;
	}else{ //both true 
		cout << "(";
		func(y,x, n/2); //�� 1 ��и�
		func(y,x + n/2, n/2); //�� 2 ��и� 
		func(y+n/2, x, n/2); //�� 3 ��и� 
		func(y+n/2, x+n/2, n/2); //�� 4 ��и� 
		cout << ")";
	}
	return; 
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> board[i];
	}
	func(0,0,n);
	return 0;
}
