#include<iostream>
#include<vector>
using namespace std;
int n;
int cost[5];
int m[20][10];
bool vst[20]; //n
vector<int> a;
vector<int> b;
int ret = 987654321;
bool chk(vector<int> v){
	int tmp[5] = {0,};
	for(int i=0; i<v.size(); i++){
		for(int j=1; j<=4; j++){
			tmp[j] += m[v[i]][j];
		}
	}
	for(int i=1; i<=4; i++){
		if(tmp[i] < cost[i]) return false;
	}
	return true;
}
void go(int st, vector<int> v){
	if(chk(v)){
		int sum = 0;
		for(int i=0; i<v.size(); i++){
			sum += m[v[i]][5];
		}
		if(ret > sum){
			ret = sum;
			b.clear();
			b.assign(v.begin(), v.end());
		}
		return;
	}
	for(int i = st + 1; i <= n; i++){
		v.push_back(i);
		go(i, v);
		v.pop_back();
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1; i<=4; i++){
		cin >> cost[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=5; j++){
			cin >> m[i][j];
		}
	}
	go(0, a);
	if(ret != 987654321){
		cout << ret << '\n';
		for(auto e: b){
			cout << e << ' ';
		}
	}else{
		cout << -1;
	}
	
	return 0;
}
