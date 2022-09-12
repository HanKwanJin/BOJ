#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[51];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	if(n == 1){
		cout << arr[0]*arr[0];
	}else{
		cout << arr[0]*arr[n-1];
	}
	return 0;
}
