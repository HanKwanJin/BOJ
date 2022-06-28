#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[10];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string n;
	cin >> n;
	for(int i=0; i < n.length(); i++){
		arr[n[i] - '0']++;
	}
	arr[6] += arr[9];
	arr[9] = 0;
	
	if(arr[6] > 1){
		if(arr[6] & 1) arr[6] = arr[6] / 2 + 1;
		else arr[6] /= 2;
	}
	int mx = 0;
	for(int i=0; i<=9; i++){
		mx = max(mx, arr[i]);
	}
	
	cout << mx;
	return 0;
}
