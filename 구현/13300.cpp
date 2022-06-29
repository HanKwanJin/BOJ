#include<iostream>
using namespace std;

int n,k,s,y; //성별 0 -> 여자 1-> 남자 
int mem[2][7];
int ret;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> s >> y;
		mem[s][y]++;
		if(mem[s][y] >= k){
			mem[s][y] = 0;
			ret++;
		}
	}
	for(int i=0; i<2; i++){
		for(int j=1; j<=6; j++){
			if(mem[i][j] > 0) ret++;
		}
	}
	cout << ret;
	return 0;
}
