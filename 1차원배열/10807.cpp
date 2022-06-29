#include<iostream>
using namespace std;

int arr[204];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		arr[x+100]++;	
	}
	cin >> m;
	cout << arr[m+100];
	return 0;
}
