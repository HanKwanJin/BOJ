//도로포장
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, pii> plpii;
const int MAX = 10001;
int v,e,k;
int cnt;
ll dist[MAX][21];
vector<pii> vec[MAX];

void fun(){
    priority_queue<plpii, vector<plpii>, greater<plpii>> pq;
    dist[1][0] = 0;
    pq.push({0,{1,0}});
    while(!pq.empty()){
        ll cost = pq.top().first;
        int cur = pq.top().second.first;
        int cnt = pq.top().second.second;
        pq.pop();
        if(cost > dist[cur][cnt]) continue;
        for(int i=0; i < vec[cur].size(); i++){
            int nxt = vec[cur][i].first;
            int w = vec[cur][i].second;
            //포장하지 않았을 때
            if(dist[nxt][cnt] > cost + w){
                dist[nxt][cnt] = cost + w;
                pq.push({dist[nxt][cnt], {nxt, cnt}});
            }
            //포장한 경우
            if(cnt < k && dist[nxt][cnt+1] > cost){
                dist[nxt][cnt+1] = cost;
                pq.push({dist[nxt][cnt+1], {nxt, cnt+1}});
            }
        }
    }
    
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> k;
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }
    for(int i=1; i<=v; i++){
        for(int j=0; j<=k; j++){
            dist[i][j] = 1e15;
        }
    }
    fun();
    ll ret =1e15;
    for(int i=0; i<=k; i++) ret = min(ret, dist[v][i]);
    cout << ret;
    return 0;
}