//최단 경로
#include<bits/stdc++.h>
#define MAX 20001
using namespace std;
const int INF = 987654321;
int v,e, st;
int dist[MAX];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    cin >> st; //시작 노드
    vector<pair<int,int>> vec[MAX];
    for(int i=0; i<e; i++){
        int a,b,c; 
        cin >> a >> b >> c;
        vec[a].push_back({b,c});
    }
    for(int i=1; i<= v; i++) dist[i] = INF;

    priority_queue<pair<int,int>> pq;
    pq.push({0, st});
    dist[st] = 0;

    while(!pq.empty()){
        int d = -pq.top().first;
        int u = pq.top().second; pq.pop();
        for(int i=0; i< vec[u].size(); i++){
            int nx = vec[u][i].first;
            int w = vec[u][i].second;
            if(dist[nx] > d + w){
                dist[nx] = d + w;
                pq.push({-dist[nx], nx});
            }
        }
        
    }
    for(int i =1; i<=v; i++){
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}