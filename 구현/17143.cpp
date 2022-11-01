#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct shark
{
    int y;
    int x;
    int speed;
    int dir;    
    int size;
    int death;
}a[104*104];
int n,m,k, ret;
const int dx[5] = {0,0,0,1,-1};
const int dy[5] = {0,-1,1,0,0};
int table[104][104];
int tmp[104][104];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    
    for(int i=1; i<=k; i++){
        cin >> a[i].y >> a[i].x >> a[i].speed >> a[i].dir >> a[i].size;
        a[i].y -= 1; a[i].x -=1;
        table[a[i].y][a[i].x] = i;
    }
    for(int x=0; x<m; x++){ //낚시왕의 움직임
        for(int y=0; y<n; y++){ //낚시왕과 가장 가까운 곳의 물고기를 잡음
            if(table[y][x]){
                a[table[y][x]].death = 1;
                ret += a[table[y][x]].size;
                table[y][x] = 0;
                break;
            }
        }
        memset(tmp, 0, sizeof(tmp));
        for(int s = 1; s <= k; s++){
            if(a[s].death) continue;
            int _y = a[s].y;
            int _x = a[s].x;
            int d = a[s].dir;
            int sp = a[s].speed;
            int ny,nx;
            while(1){
                ny = _y + sp*dy[d];
                nx = _x + sp*dx[d];
                if(nx < m && ny < n && nx >= 0 && ny >= 0) break;
                if(d == 1 &&  ny < 0) {d = 2; sp -= _y; _y = 0;}
                else if(d == 2 && ny >= n) {d = 1; sp -= n - 1 - _y; _y = n -1;}
                else if(d == 3 && nx >= m) {d = 4; sp -= m - 1 - _x; _x = m -1;}
                else if(d == 4 && nx < 0) {d = 3; sp -= _x; _x = 0;}
            } 
            if(tmp[ny][nx]){
                //같은 곳에 2마리 이상의 상어가 존재
                if(a[tmp[ny][nx]].size < a[s].size) {a[tmp[ny][nx]].death = 1; tmp[ny][nx] = s;}
                else a[s].death = 1;
            }else{
                tmp[ny][nx] = s;
            }
            a[s].y = ny;
            a[s].x = nx;
            a[s].dir = d;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                table[i][j] = tmp[i][j];
            }
        }
    }
    cout << ret;
    return 0;
}