#include<iostream>
#include<string>
using namespace std;

int d[26];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		d[s[i] - 'a']++;
	}
	for(int i=0; i<26; i++){
		cout << d[i] << ' ';
	}
	return 0;
}
