//부녀회장이 될테야
#include<bits/stdc++.h>
using namespace std;

int func(int k, int n){
    int d[15][15] = {0,};
    for(int i=0; i<= k; i++){
        for(int j=1; j<=n; j++){
            if(i==0) d[0][j] = j;
            else if(j==1) d[i][1] =1;
            else d[i][j] = d[i-1][j] + d[i][j-1];
        }
    }
    return d[k][n];
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,k,n;
    cin >> t;
    while(t--){
        cin >> k >> n;
        cout << func(k,n) << '\n';
    }
}