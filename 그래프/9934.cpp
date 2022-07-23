#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int k;
vector<int> v;
vector<int> ret[14];

void func(int st, int en, int h){
	if(st > en) return;
	int root = (st + en) / 2;
	if(st == en){
		ret[h].push_back(v[st]);
		return;
	}
	ret[h].push_back(v[root]);
	func(st, root - 1, h + 1);
	func(root + 1, en, h+1);
	return;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	for(int i=0; i< (int)pow(2, k) - 1; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	func(0, v.size() - 1,0);
	for(int i=0; i<k; i++){
		for(auto e: ret[i]){
			cout << e << ' ';
		}
		cout << '\n';
	}
	return 0;
}
