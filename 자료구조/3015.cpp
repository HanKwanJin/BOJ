#include<iostream>
#include<stack>
#include<utility>
typedef long long ll;
using namespace std;
ll n,ret;
stack<pair<ll,ll>> st;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		ll x,cnt;
		cin >> x;
		cnt = 1;
		while(st.size() && st.top().first <= x){
			ret += st.top().second;
			if(st.top().first == x){
				cnt = st.top().second + 1;
			}else{
				cnt = 1;
			}
			st.pop();
		}
		if(st.size()) ret++;
		st.push({x, cnt});
	}
	cout << ret;
	return 0;
}
