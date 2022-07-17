#include<iostream>
#include<queue>
using namespace std;
int n,k;
int d[100005];
int cnt[100005];
void fastio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main(void){
	fastio();
	cin >> n >> k;
	if(n == k){
		cout << 0 << '\n' << 1;
		return 0;
	}
	cnt[n] = 1;
	queue<int> q;
	q.push(n);
	
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int nxt: {cur-1, cur+1, cur*2}){
			if(nxt < 0 || nxt > 100000) continue;
			if(d[nxt] == d[cur] + 1) cnt[nxt] += cnt[cur];
			if(d[nxt]) continue;
			d[nxt] = d[cur] + 1;
			cnt[nxt] += cnt[cur];
			q.push(nxt);
		}
	}
	
	cout << d[k] << '\n';
	cout << cnt[k];
}
