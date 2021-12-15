//9461 파도반 수열
#include<bits/stdc++.h>
using namespace std;

int t, n;
long long d[101];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 3){
            cout << 1 << '\n';
            continue;
        }
        d[1] = 1;
        d[2] = 1;
        d[3] = 1;
        for(int i=4; i<=n; i++){
            d[i] = d[i-3] + d[i-2];
        }
        cout << d[n] << '\n';
    }

}