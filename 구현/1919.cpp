#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int d[2][26];
int ret;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0; i<2; i++){
		string s;
		cin >> s;
		for(int j=0; j<s.length(); j++){
			d[i][s[j]-'a']++;
		}
	}
	for(int i=0; i<26; i++){
		if(d[0][i] != d[1][i]){
			ret += abs(d[0][i] - d[1][i]);
		}
	}
	cout << ret;
	return 0;
}
