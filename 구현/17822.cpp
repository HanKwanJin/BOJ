#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,t;
int x,d,k;
bool flag;
int a[52][52];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool vst[52][52];

void dfs(int y, int x){
    for(int dir=0; dir<4; dir++){
        int ny = y + dy[dir];
        int nx = (x + dx[dir] + m) % m;
        if(ny < 0 || ny >=n) continue;
        if(vst[ny][nx]) continue;
        if(a[y][x] == a[ny][nx]){
            vst[y][x] = 1;
            vst[ny][nx] = 1;
            flag = true;
            dfs(ny,nx);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;

    //init
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<t; i++){
        cin >> x >> d >> k;
        //rotate
        for(int j=x; j<=n; j+=x){
            if(d == 0){
                rotate(a[j-1], a[j-1]+m-k, a[j-1] + m);
            }else{
                rotate(a[j-1], a[j-1] + k, a[j-1] + m);
            }
        }
        //adj delete
        memset(vst, 0, sizeof(vst));
        flag = false;
        for(int j=0; j<n; j++){
            for(int z=0; z<m; z++){
                if(a[j][z] == 0) continue;
                if(vst[j][z]) continue;
                dfs(j,z);
            }
        }
        for(int j=0; j<n; j++){
            for(int z=0; z<m; z++){
                if(vst[j][z]){
                    a[j][z] = 0;
                }
            }
        }

        if(!flag){
            //avg
            int sum = 0;
            int cnt = 0;
            for(int j=0; j<n; j++){
                for(int z=0; z<m; z++){
                    if(a[j][z] == 0) continue;
                    sum += a[j][z];
                    cnt++;
                }
            }
            double av = (double)sum / (double)cnt;
            for(int j=0; j<n; j++){
                for(int z=0; z<m; z++){
                    if(a[j][z] == 0) continue;
                    if((double)a[j][z] > av) a[j][z]--;
                    else if((double)a[j][z] < av) a[j][z]++;
                }
            }
        }
    }
    int ret = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ret += a[i][j];
        }
    }
    cout << ret;
    return 0;
}