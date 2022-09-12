#include<iostream>
using namespace std;
int a,b;
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	cout << gcd(a,b) << '\n';
	cout << a*b / gcd(a,b);
	return 0;
}
