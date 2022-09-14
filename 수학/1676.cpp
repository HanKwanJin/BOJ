#include<bits/stdc++.h>
using namespace std;
int n;
int arr;
void func(int a){
	int tmp = a;
	while(1){
		bool flag = false;
		if(tmp % 5 == 0){
			arr++;
			tmp /= 5;
			flag = true;
		}
		if(!flag) break;
	}
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		if(i % 5 == 0){
			func(i);
		}
	}
	cout << arr;
	return 0;
}
