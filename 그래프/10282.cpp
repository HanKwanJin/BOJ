//해킹
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 987654321;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int v,e,k,a,b,s;
        cin >> v >> e >> k;
        vector<vector<pii>> vec(v+1);
        for(int i=0; i< e; i++){
            cin >> a >> b >> s;
            vec[b].push_back({a,s});
        }
        vector<int> dist(v+1, INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int d = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            
            if(d > dist[cur]) continue;
            for(auto&p: vec[cur]){
                int nxt = p.first;
                int w = p.second + d;
                if(dist[nxt] > w) {
                    dist[nxt] = w;
                    pq.push({dist[nxt], nxt});    
                }
            }
        }
        int cnt = 0;
        int ans = 0;
        for(int i=1; i<=v; i++){
            if(dist[i] != INF){
                cnt++;
                ans = max(ans, dist[i]);
            }
        }
        cout << cnt << ' ' << ans << '\n';
    }
    return 0;
}