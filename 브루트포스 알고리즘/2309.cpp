#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//O(9C7) O(9P7) 
int a[10];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0; i<9; i++){
		cin >> a[i];
	}
	sort(a,a+9);
	do{
		int sum = 0;
		for(int i=0; i<7; i++) sum += a[i];
		if(sum == 100) break;
	}while(next_permutation(a, a+9));
	for(int i=0; i<7; i++) cout << a[i] << '\n';
	return 0; 
}
