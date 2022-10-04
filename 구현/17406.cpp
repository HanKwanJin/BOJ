#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<deque>
#include<utility>
using namespace std;
int n,m,k,mx,sy,sx,ex,ey,dir;
int a[54][54];
int b[54][54];
const int INF = 987654321;
int ret = INF;
int vst[54][54];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
vector<pair<int,int>> vv;
vector<int> vdx;
struct A
{
    int y,x,cnt;
};
vector<A> v;
bool cmp(A &a, A &b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
void go(int y, int x, int first){
    if(!first && y == sy && x == sx) dir++;
    if(!first && y == sy && x == ex) dir++;
    if(!first && y == ey && x == sx) dir++;
    if(!first && y == ey && x == ex) dir++;

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if(vst[ny][nx]) return;
    vst[ny][nx] = 1;
    vv.push_back({ny,nx});
    go(ny,nx,0);
}
void rotateAll(int y, int x, int cnt){
    for(int i=1; i<=cnt; i++){
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;
        vv.clear();
        dir = 0;
        memset(vst, 0, sizeof(vst));
        vst[sy][sx] = 1;
        vv.push_back({sy,sx});
        go(sy,sx, 1);
        vector<int> vvv;
        for(pair<int,int> c : vv) vvv.push_back(b[c.first][c.second]);
        rotate(vvv.begin(), vvv.begin()+ vvv.size()-1, vvv.end());
        for(int i=0; i<vv.size(); i++) b[vv[i].first][vv[i].second] = vvv[i];
    }
}
int solve(){
    for(int i : vdx) rotateAll(v[i].y, v[i].x, v[i].cnt);
    int _ret = INF;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++) cnt += b[i][j];
        _ret = min(_ret, cnt);
    }
    return _ret;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    int r,c,s;    
    for(int i=0; i<k; i++){
        cin >> r >> c >> s; r--; c--;
        v.push_back({r,c,s});
        vdx.push_back(i);
    }
    do{
        memcpy(b, a, sizeof(b));
        ret =  min(ret, solve());
    }while(next_permutation(vdx.begin(), vdx.end()));
    cout << ret << '\n';
    return 0;
}