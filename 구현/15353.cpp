#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a,b;
int num1[10004], num2[10004];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	if(a.size() < b.size()){
		swap(a,b);
	}
	for(int i=1; i <= a.size(); i++){
		num1[i] = a[i-1] - '0';
	}
	for(int i=0; i < b.size(); i++){
		num2[i+1+a.size()-b.size()] = b[i] -'0';
	}
	for(int i=a.size(); i > 0; i--){
		int sum = num1[i] + num2[i];
		if(sum >= 10){
			num1[i-1]++;
		}
		num1[i] = sum % 10;
	}
	for(int i=0; i<=a.size(); i++){
		if(i== 0 && num1[0] == 0) continue;
		cout << num1[i];
	}
	return 0;
}
