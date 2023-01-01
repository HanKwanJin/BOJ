#include<iostream>
#include<algorithm>
using namespace std;
int n;
int d[1004];
int len;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		auto pos = lower_bound(d, d+len, x);
		*pos = x;
		if(pos == d + len) len++;
	}
	cout << len;
	return 0;
}
