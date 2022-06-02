#include<iostream>
using namespace std;
typedef long long ll;
ll d[1000002];
ll g[1002];
ll ret;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        x %= m;
        d[i] = (d[i-1] + x) % m;
        if(d[i] == 0) ret++;
        g[d[i]]++;
    }
    for(int i=0; i<m; i++){
        ret += (g[i] * (g[i] -1)) / 2;
    }
    cout << ret;
    return 0;
}