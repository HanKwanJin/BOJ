//쉬운 계단 수
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll d[101][11];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    //d[1][0] = 0;
    for(int i=1; i <= 9; i++){
        d[1][i] = 1;
    }

    for(int i=2; i <= n; i++){
        for(int j=0; j<=9; j++){
            if(j == 0) d[i][j] = d[i-1][j+1] % 1000000000;
            else if(j == 9) d[i][j] = d[i-1][j-1] % 1000000000;
            else{
                d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
            }
        }
    }
    ll ret =0;
    for(int i =0; i<= 9; i++){
        ret += d[n][i];
    }

    cout << ret  % 1000000000;
}