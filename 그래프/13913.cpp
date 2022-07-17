#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int n,k;
int d[100005], prv[100005];
queue<int> q;
int main(void){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if(n == k){
		cout << 0 << '\n';
		cout << n;
		return 0;
	}
	q.push(n);
	while(!d[k]){
		auto cur = q.front(); q.pop();
		for(int nxt : {cur-1, cur+1, cur*2}){
			if(nxt < 0 || nxt > 100000) continue;
			if(d[nxt]) continue;
			d[nxt] = d[cur] + 1;
			prv[nxt] = cur;
			q.push(nxt);
		}
	}
	deque<int> dq = {k};
	while(dq.front() != n){
		dq.push_front(prv[dq.front()]);
	}
	cout << d[k] << '\n';
	for(auto e : dq){
		cout << e << ' ';
	}
}
