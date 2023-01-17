#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int a[100004][4];
int mx[2][4];
int mn[2][4];
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=3; j++){
			cin >> a[i][j];
			if(i == 1){
				mx[0][j] = a[i][j]; //첫줄까지 최댓값 
				mn[0][j] = a[i][j]; //첫줄까지 최솟값 
			}
		}
	}
	
	for(int i=2; i<=n; i++){
		mx[1][1] = a[i][1] + max(mx[0][1], mx[0][2]);
		mx[1][2] = a[i][2] + max({mx[0][1], mx[0][2], mx[0][3]});
		mx[1][3] = a[i][3] + max(mx[0][2], mx[0][3]);
		
		mx[0][1] = mx[1][1];
		mx[0][2] = mx[1][2];
		mx[0][3] = mx[1][3];
		
		mn[1][1] = a[i][1] + min(mn[0][1], mn[0][2]);
		mn[1][2] = a[i][2] + min({mn[0][1], mn[0][2], mn[0][3]});
		mn[1][3] = a[i][3] + min(mn[0][2], mn[0][3]);
		
		mn[0][1] = mn[1][1];
		mn[0][2] = mn[1][2];
		mn[0][3] = mn[1][3];
	} 
	
	cout << max({mx[0][1], mx[0][2], mx[0][3]}) << ' ' << min({mn[0][1], mn[0][2], mn[0][3]});
	return 0;
}
