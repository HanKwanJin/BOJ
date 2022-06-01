#include<iostream>
using namespace std;
int cnt[101];
int sum;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a,b,c;
	cin >> a >> b >> c;

	for(int i=0; i < 3; i++){
		int st, en;
		cin >> st >> en;
		for(int j=st; j<en; j++) cnt[j]++;	
	}
	for(int i=1; i<= 100; i++){
		if(cnt[i] == 1) sum += a;
		else if(cnt[i] == 2) sum += b * 2;
		else if(cnt[i] == 3) sum += c * 3;
	}
	cout << sum; 
	return 0;
}
