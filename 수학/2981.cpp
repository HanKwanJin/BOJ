#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n;
int arr[102];
int ret;
set<int> s;
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
	sort(arr, arr+n);
	ret = arr[1] - arr[0];
	for(int i=2; i<n; i++){
		ret = gcd(ret, arr[i] - arr[i-1]);
	}
	for(int i=1; i*i <= ret; i++){
		if(ret % i == 0){
			s.insert(i);
			s.insert(ret / i);
		}
	}
	for(auto e: s){
		if(e == 1) continue;
		cout << e << ' ';
	}
	return 0;
}
