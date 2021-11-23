#include<bits/stdc++.h> 
using namespace std;

int board[501][501]; 
int d[501][501];

int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1; i<= n; i++){
        for(int j=1; j<= i; j++){
            cin >> board[i][j];
        }
    }

    d[1][1] = board[1][1];

    for(int i=2; i<= n; i++){
        for(int j=1; j<= i; j++){
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + board[i][j];
        }
    }

    int ret = -9999;
    for(int i= 1; i<= n; i++){
        ret = max(ret, d[n][i]);
    }

    cout << ret;

}
