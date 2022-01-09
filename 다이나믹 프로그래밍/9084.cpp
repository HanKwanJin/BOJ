//동전
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int t,n,m;
int coin[21];
ll d[10001]; // d[a] = b  -> a원을 만들 수 있는 b가지 방법
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        memset(coin, 0, sizeof(coin));
        memset(d,0,sizeof(d));
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> coin[i];
        }
        d[0] = 1;
        cin >> m;
        for(int i= 1; i<=n; i++){
            for(int j= coin[i]; j<=m; j++){
                d[j] += d[j- coin[i]];
            }
        }
        cout << d[m] << '\n';
    }
}