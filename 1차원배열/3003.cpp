#include<iostream>
using namespace std;
int a[6] = {1,1,2,2,2,8};
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0; i<6; i++){
		int x;
		cin >> x;
		cout << a[i] - x << ' ';
	}
	return 0;
}
