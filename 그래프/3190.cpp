#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<deque>
#include<utility>
#define Y first
#define X second
using namespace std;
int n,k,l;
int a[104][104];
int dir[10004];
bool vst[104][104];
int curDir = 0; //현재 보고 있는 방향; 초기값 오른쪽
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
deque<pair<int,int>> q;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int y,x;
        cin >> y >> x;
        a[y][x] = 2; //사과
    }
    cin >> l;
    for(int i=0; i<l; i++){
        int x;
        char c;
        cin >> x >> c;
        if(c == 'L'){
            dir[x] = 1;
        }else if(c == 'D'){
            dir[x] = 3;
        }
    }
    q.push_front({1,1}); //뱀은 맨 왼쪽 위에서 부터 시작함
    vst[1][1] = 1;
    int time = 0;
    int cnt = 1; //몸 길이
    while(1){
        auto here = q.front();
        if(dir[time]) curDir = (curDir + dir[time]) % 4;
        int ny = here.Y + dy[curDir];
        int nx = here.X + dx[curDir];
        time++;
        if(nx <= 0 || ny <= 0 || nx > n || ny > n || vst[ny][nx]) break;
        //queue를 이용해서 뱀의 몸이 어느 위치에 있는지 다 넣어주기 머리부터 꼬리까지.
        if(a[ny][nx] == 2){
            //사과 먹고 머리 부분 늘려줌
            a[ny][nx] = 0;
            q.push_front({ny,nx});
            vst[ny][nx] = 1;
        }else{
            auto tail = q.back();
            vst[tail.Y][tail.X] = 0;
            q.pop_back();
            q.push_front({ny,nx});
            vst[ny][nx] = 1;
        }
    }
    cout << time << '\n';
    return 0;
}