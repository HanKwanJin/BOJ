//숨바꼭질
#include<bits/stdc++.h>
using namespace std;
int dist[100005];
int n,k;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    queue<int> q;
    fill(dist, dist+100001, -1);
    q.push(n);
    dist[n] = 0;
    while(dist[k] == -1){
        int cur = q.front(); q.pop();
        for(int i : {cur-1, cur+1, cur*2}){
            if(i < 0 || i > 100000) continue;
            if(dist[i] != -1) continue;
            dist[i] = dist[cur] + 1;
            q.push(i);
        }
    }
    cout << dist[k];
}