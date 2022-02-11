#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int board[21][21];
int n;
int cnt;
int sum=INF;
int chk[21];
void func(int k, int idx){
    if(k == n / 2){
        // n/2명 고르면 합을 구함
        int a = 0, b = 0;
        for(int i = 1; i<=n; i++){
            for(int j=1; j<= n; j++){
                if(chk[i] && chk[j]) a += board[i][j];
                if(!chk[i] && !chk[j]) b += board[i][j];
            }
        }
        int tmp = abs(a-b);
        sum = min(sum, tmp);
        return;
    }
    for(int i = idx; i<n; i++){
        chk[i] = true;
        func(k+1, i+1);
        chk[i] = false;
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    func(0,1);
    cout << sum << '\n';
    return 0;   
}