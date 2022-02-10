//스도쿠
#include<bits/stdc++.h>
using namespace std;
int board[10][10];
bool row[10][10]; //y 
bool col[10][10]; //x
bool square[10][10];
void print(){
    for(int i=0; i< 9; i++){
        for(int j=0; j<9; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}
void func(int n){ //백트래킹
    int y = n / 9;
    int x = n % 9;
    if(n == 81){
        print();
        exit(0);
    }
    if(board[y][x] == 0){
        for(int i = 1; i<=9; i++){
            if(!row[y][i] && !col[x][i] && !square[(y/3)*3+(x/3)][i]){
                row[y][i] = true;
                col[x][i] = true;
                square[(y/3)*3+(x/3)][i] = true;
                board[y][x] = i;
                func(n+1);
                board[y][x] = 0;
                row[y][i] = false;
                col[x][i] = false;
                square[(y/3)*3+(x/3)][i] = false;
            }

        }
    }else func(n+1);
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i< 9; i++){
        for(int j=0; j< 9; j++){
            cin >> board[i][j];
            if(board[i][j] != 0){
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                square[(i/3)*3+(j/3)][board[i][j]] = true;
            }
        }
    }
    func(0);
    return 0;
}