#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,t;
bool chk(int x, vector<int> &v){
	int st = 0, en = v.size() - 1;
	int mid;
	while(st <= en){
		mid = (st + en) / 2;
		if(x == v[mid]){
			return true;
		}else if(x > v[mid]){
			st = mid + 1;
		}else{
			en = mid - 1;
		}
	}
	return false;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> v;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		cin >> n;
		sort(v.begin(), v.end());
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			if(chk(x, v)){
				cout << 1 << '\n';
			}else{
				cout << 0 << '\n';
			}
		}
	}
}
