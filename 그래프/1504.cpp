//특정한 최단 경로
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAX = 810;
const int INF = 987654321;

int n,e;
int v1,v2;
int dist[MAX];
vector<pii> vec[MAX];
void fun(int st){ //dijkstra
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[st] = 0;
    pq.push({0, st});
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second; pq.pop();
        for(int i=0; i<vec[cur].size(); i++){
            int nxt = vec[cur][i].first;
            int w = cost + vec[cur][i].second;
            if(dist[nxt] > w){
                dist[nxt] = w;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> e;
    
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        //양방향
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    }

    cin >> v1 >> v2;
    bool fa = true;
    bool fb = true;
    
    for(int i=1; i<= n; i++) dist[i] = INF; 
    fun(1); //1-> v1, 1->v2
    int ra = dist[v1];
    int rb = dist[v2];
    if(ra == INF) fa = false;
    if(rb == INF) fb = false;
    if(fa == false && fb == false){
        cout << -1;
        return 0;
    }
    for(int i=1; i<= n; i++) dist[i] = INF;
    fun(v1); //v1 -> v2 == v2 -> v1
    if(fa == true) ra += dist[v2];
    if(fb == true) rb += dist[v2];

    for(int i=1; i<= n; i++) dist[i] = INF;
    fun(v2); //ra == (v1 ->v2) -> n
    if(fa == true) ra += dist[n];
    
    for(int i=1; i<= n; i++) dist[i] = INF;
    fun(v1); //rb == (v2 -> v1) -> n
    if(fb == true) rb += dist[n];

    int ret = min(ra, rb);
    cout << (ret == INF ? -1: ret);
    return 0;
}