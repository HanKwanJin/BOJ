#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
const int INF = 987654321;
int n,k,ret;
int cnt[104], a[104];
bool vst[104];
vector<int> v;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=0; i<k; i++) cin >> a[i];
	for(int i=0; i<k; i++){
		if(!vst[a[i]]){
			if(v.size() == n){
				int last = 0,pos;
				for(auto e : v){
					int here = INF;
					for(int j=i+1; j<k; j++){
						if(e == a[j]){
							here = j;
							break;
						}
					}
					if(last < here){
						last = here;
						pos = e;
					}
				}
				vst[pos] = 0;
				ret++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(a[i]); vst[a[i]] = 1;
		}
	}
	cout << ret << '\n';
	return 0;
}
