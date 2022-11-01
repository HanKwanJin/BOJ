#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int v[104];
int mal[4];
vector<int> adj[104];
int dice[10];
void init(){
    for(int i=0; i<=19; i++){
        adj[i].push_back(i+1);
    }
    adj[5].push_back(21); adj[21].push_back(22); adj[22].push_back(23); adj[23].push_back(24);
    adj[10].push_back(27); adj[27].push_back(28); adj[28].push_back(24);
    adj[15].push_back(29); adj[29].push_back(30); adj[30].push_back(31); adj[31].push_back(24);
    adj[24].push_back(25); adj[25].push_back(26); adj[26].push_back(20); 
    adj[20].push_back(100); //끝임

    v[1] = 2; v[2] = 4; v[3] = 6; v[4] = 8; v[5] = 10;
    v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
    v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
    v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;
    v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25;
    v[25] = 30; v[26] = 35;
    v[27] = 22; v[28] = 24;
    v[29] = 28; v[30] = 27; v[31] = 26;
}

int move(int here, int cnt){
    if(here == 100) return 100;
    if(adj[here].size() >= 2){
        here = adj[here][1];
        cnt--;
    }
    if(cnt){
        queue<int> q;
        q.push(here);
        int there;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            there = adj[cur][0];
            q.push(there);
            if(there == 100) break;
            cnt--;
            if(cnt == 0) break;
        }
        return there;
    }else return here;
}
bool isMal(int midx, int idx){
    if(midx == 100) return false;
    for(int i=0; i<4; i++){
        if(i == idx) continue;
        if(mal[i] == midx) return true;
    }
    return false;
}
int go(int here){
    if(here == 10) return 0;
    int ret = 0;
    for(int i=0; i<4; i++){
        int tmp = mal[i];
        int midx = move(tmp, dice[here]);
        if(isMal(midx, i)) continue;
        mal[i] = midx;
        ret = max(ret, go(here+1) + v[midx]);
        mal[i] = tmp;
    }
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    for(int i=0; i < 10; i++){
        cin >> dice[i];
    }
    cout << go(0) << '\n';
    return 0;
}