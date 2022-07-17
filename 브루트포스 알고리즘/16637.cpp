#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
int n,mx = -987654321;
string s;
vector<int> num;
vector<char> oper;

void fastio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int op(char a, int b, int c){
	if(a == '+') return b + c;
	if(a == '-') return b - c;
	if(a == '*') return b * c;
}
void go(int cur, int ret){
	if(cur == num.size() - 1){
		mx = max(mx, ret);
		return;
	}
	go(cur + 1, op(oper[cur], ret, num[cur + 1]));
	if(cur + 2 <= num.size() - 1){
		int tmp = op(oper[cur + 1], num[cur + 1], num[cur + 2]);
		go(cur + 2, op(oper[cur], ret, tmp));
	}
}

int main(void){
	fastio();
	cin >> n;
	cin >> s;
	for(int i=0; i<n; i++){
		if(i % 2 == 0) num.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}
	go(0, num[0]);
	cout << mx;
	return 0;
}
