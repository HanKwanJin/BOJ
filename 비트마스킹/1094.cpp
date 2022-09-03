#include<iostream>
using namespace std;

int x;
int ret;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> x;
	for(int i=0; i <= 6; i++){
		if(x & (1 << i)) ret++;
	}
	cout << ret;
	return 0;
}
