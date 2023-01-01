#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
int n;
double d[10004];
double mx;
double ret;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> d[i];
	}
	ret = d[0];
	for(int i=1; i<n; i++){
		if(d[i] > ret * d[i]) ret = d[i];
		else ret *= d[i];
		mx = max(mx, ret);
	}
	printf("%.3lf", mx);
	return 0;
}
