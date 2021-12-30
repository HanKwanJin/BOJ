//돌 게임 3
#include<bits/stdc++.h>
using namespace std;
int n;
int d[1001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    //1번은 상근이 승리
    //0번은 창영이 승리
    d[1] = 1;
    d[2] = 0;
    d[3] = 1;
    d[4] = 1;
    for(int i=5; i<= n; i++){
        if(d[i-1] && d[i-3] && d[i-4]){
            d[i] = 0;
        }else{
            d[i] = 1;
        }
    }
    if(d[n] == 1){
        cout << "SK" << '\n';
    }else{
        cout << "CY" << '\n';
    }
}
