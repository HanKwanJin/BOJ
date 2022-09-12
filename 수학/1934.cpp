#include<iostream>
using namespace std;
int t;

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		cout << a * b / gcd(a,b) << '\n';
	}
	return 0;
}
