#include<iostream>
using namespace std;
int n;
int arr[103];
int ret;
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=1; i<n; i++){
		ret = gcd(arr[0], arr[i]);
		cout << arr[0] / ret << "/" << arr[i] / ret << '\n';
	}
	return 0;
}
