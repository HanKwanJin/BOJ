#include<iostream>
#include<algorithm>
using namespace std;
int N;
int a[132][132];
int one, zero;
void func(int y, int x, int n){
	if(n == 1){
		if(a[y][x] == 1) one++;
		else zero++;
		return;
	}
	bool z = false;
	bool o = false;
	for(int i=y; i<y+n; i++){
		for(int j=x; j<x+n; j++){
			if(a[i][j] == 1) o = true;
			else z = true;
		}
	}
	
	if(o && !z){
		one++;
	}else if(z && !o){
		zero++;
	}else{
		func(y,x,n/2);
		func(y + n/2, x, n/2);
		func(y, x+n/2, n/2);
		func(y+n/2, x+n/2, n/2);
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> a[i][j];
		}
	}
	func(0,0,N);
	cout << zero << '\n';
	cout << one;
	return 0;
}
