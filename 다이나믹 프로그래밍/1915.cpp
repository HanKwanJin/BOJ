//가장 큰 정사각형
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1001;
int n,m;
ll ret;
ll d[MAX][MAX];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++){
            d[i][j] = s[j-1] - '0';
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(d[i][j] != 0){
                d[i][j] = min({d[i-1][j-1], d[i-1][j], d[i][j-1]}) + 1;
                ret = max(ret, d[i][j]);
            }
        }
    }
    cout << ret*ret;
}
