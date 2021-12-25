//오르막 수
#include<bits/stdc++.h>
#define m 10007
using namespace std;
typedef long long ll;
int n;
ll d[1001][11]; // d[a][b] a자리 수 일때 마지막 숫자가 b인 경우의 수
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<= 9; i++){
        d[1][i] = 1;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<= 9; j++){
            for(int k=0; k<=j; k++){
                d[i][j] += (d[i-1][k]) % m;
            }
        }
    }
    int ans =0;
    for(int i=0; i<= 9; i++){
        ans += d[n][i];
    }
    ans %= m;
    cout << ans;

}