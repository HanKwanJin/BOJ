//색상환
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000003;
const int MAX = 1001;
int n, k;
ll dp[MAX][MAX]; //dp[a][b] : a색상환일대 b개를 고르는 경우의 수

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    //i색상환일때 1개 고르는 경우의 수는 i이다.
    for(int i=1; i<=n; i++){
        dp[i][1] = i;
        dp[i][0] = 1;
    }
    for(int i=4; i<=n; i++){
        for(int j=2; j<=k; j++){
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % mod;
        }
    }
    
    cout << dp[n][k] % mod;
}