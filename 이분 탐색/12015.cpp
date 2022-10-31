#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ret;
int d[1000004];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> m;
        auto pos = lower_bound(d+1, d+ret+1, m);
        *pos = m;
        if(pos == d + ret + 1){
            ret++;
        }
    }
    cout << ret;
    return 0;
}
