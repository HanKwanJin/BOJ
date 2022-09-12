#include<iostream>
using namespace std;
int n,k;
int ret = 1;
int func(int a){
	if(a == 1) return 1;
	return a * func(a-1);
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	k = min(k, n-k);
	for(int i=0; i<k; i++){
		ret *= n--;
	}
	
	if(k == 0) cout << 1;
	else cout << ret/func(k);
	
	return 0;
}
