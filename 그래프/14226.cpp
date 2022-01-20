//이모티콘
#include<bits/stdc++.h>
using namespace std;
int s;
bool vst[2002][2002]; 
// vst[a][b]: 화면에 a 개 클립보드에 b개 있을 때 방문여부
queue<pair<pair<int,int>,int>> q; //q.push({{a,b}, c}): a,b 위와 동일/ c는 걸린 시간
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    vst[1][0] = true;
    //처음 화면에 1개의 이모티콘 있고 클립보드에는 0개의 이모티콘
    q.push({{1,0},0}); 
    while(!q.empty()){
        int w = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        if(w == s){ cout << t; return 0;}
        if(w > 0 && w < 2000){
            //1번 연산
            if(!vst[w][w]){
                vst[w][w] = true;
                q.push({{w,w}, t+1});
            }
            //3번 연산
            if(!vst[w-1][c]){
                vst[w-1][c] = true;
                q.push({{w-1,c}, t+1});
            }
        }
        if(c > 0 && w + c < 2000){
            //2번 연산
            if(!vst[w+c][c]){
                vst[w+c][c] = true;
                q.push({{w+c,c}, t+1});
            }
        }

    }
}