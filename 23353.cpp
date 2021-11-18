#include<bits/stdc++.h>
using namespace std;

int d[4][1001][1001]; //검은 돌만 있을 경우
int p[4][1001][1001]; //검은 돌 + 흰 돌

int board[1001][1001];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int m =0;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    //검은 돌 끼리만 있을 때
    for(int i = n-1; i >= 0; i--){
        for(int j=n-1; j >= 0; j--){
            if(board[i][j] == 1){
                d[0][i][j] = d[0][i][j+1] + 1;
                d[1][i][j] = d[1][i+1][j] + 1;
                d[2][i][j] = d[2][i+1][j+1] + 1; // '\'
                d[3][i][j] = d[3][i+1][j-1] + 1; // '/'
            } 
        }
    }

    //검은돌 + 흰돌
    for(int i = n-1; i >= 0; i--){
        for(int j=n-1; j >= 0; j--){
            if(board[i][j] == 2){
                p[0][i][j] = d[0][i][j+1] + 1;
                p[1][i][j] = d[1][i+1][j] + 1;
                p[2][i][j] = d[2][i+1][j+1] + 1; // '\'
                p[3][i][j] = d[3][i+1][j-1] + 1; // '/'
                m = max({m, p[0][i][j],p[1][i][j],p[2][i][j],p[3][i][j]});
            } 
        }
    }

    //최대 점수
    for(int i = n-1; i >= 0; i--){
        for(int j=n-1; j >= 0; j--){
            if(board[i][j] == 1){
                d[0][i][j] = max(d[0][i][j+1], p[0][i][j+1]) + 1;
                d[1][i][j] = max(d[1][i+1][j], p[1][i+1][j]) + 1;
                d[2][i][j] = max(d[2][i+1][j+1], p[2][i+1][j+1]) + 1;
                d[3][i][j] = max(d[3][i+1][j-1], p[3][i+1][j-1]) + 1;
                m = max({m, d[0][i][j],d[1][i][j],d[2][i][j],d[3][i][j]});
            }
        }
    }
    cout << m;

}