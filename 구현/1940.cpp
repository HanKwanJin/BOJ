#include<iostream>
#include<algorithm>
using namespace std;
int d[20001];
int cnt;
int n,m;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//2 7 4 1 5 3
	//1 2 3 4 5 7
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> d[i];
	}
	sort(d, d+n);
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(d[i] + d[j] > m) break;
			if(d[i] + d[j] == m) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
