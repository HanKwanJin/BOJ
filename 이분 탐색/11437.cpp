#include<iostream>
#include<algorithm>
#include<stack>

typedef long long ll;
using namespace std;
ll n,m,ret;
ll d[1000004];
pair<ll,ll> a[1000004];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> m;
        auto pos = lower_bound(d+1, d+ret+1, m);
        int p = lower_bound(d+1, d+1+ret,m) - (d+1);
        *pos = m;
        if(pos == d + ret + 1){
            ret++;
        }
        a[i].first = p;
        a[i].second = m;
    }
    cout << ret << '\n';
    stack<ll> ans;
    for(int i=n; i>=1; i--){
        if(a[i].first == ret-1){
            ans.push(a[i].second);
            ret--;
        }
    }
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
    return 0;
}