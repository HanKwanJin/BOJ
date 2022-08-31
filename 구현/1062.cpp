#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int words[51];
int count(int mask){
	int cnt = 0;
	for(int word: words){
		if(word && (word & mask) == word) cnt++;
	}
	return cnt;
}
int solve(int idx, int k, int mask){
	if(k < 0) return 0;
	if(idx == 26) return count(mask);
	int ret = solve(idx+1, k-1, mask | (1<<idx));
	if(idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' -'a' && idx != 'i' - 'a' && idx != 'c' - 'a'){
		ret = max(ret, solve(idx+1, k, mask));
	}
	return ret;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(char c: s){
			words[i] |= (1 << (c - 'a'));
		}
	}
	cout << solve(0,m,0);
	return 0;
}
