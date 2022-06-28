#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int ret;
int x;
bool vst[2000001];
vector<int> v;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	cin >> x; //аж╬НаЬ x
	sort(v.begin(), v.end());
	
	for(auto& e: v){
		if(e <= x && vst[x - e]) ret++;
		vst[e] = 1;
	}
	cout << ret;
	return 0;
}
