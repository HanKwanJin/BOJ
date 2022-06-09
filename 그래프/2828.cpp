#include<iostream>
#include<utility>
using namespace std;

bool d[14];
int n,m,k;
int cnt;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> k;
	pair<int,int> cur = {1,m};
	while(k--){
		int x;
		cin >> x;
		if(x < cur.first){
			int tmp = cur.first - x;
			cur.first -= tmp;
			cur.second -= tmp;
			cnt += tmp;
		}else if(x > cur.second){
			int tmp = x - cur.second;
			cur.first += tmp;
			cur.second += tmp;
			cnt += tmp;
		}
	}
	cout << cnt;
	return 0;
}
