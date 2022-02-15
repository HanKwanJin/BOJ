//주유소
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;
ll n;
ll dist[100001];
ll cost[100001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<= n-1; i++){
        cin >> dist[i];
    }
    for(int i=1; i<=n; i++){
        cin >> cost[i];
    }
    ll sum = 0;
    ll tmp = INF;
    for(int i=1; i<=n-1; i++){
        if(cost[i] < tmp){
            tmp = cost[i];
        }
        sum += tmp * dist[i];
    }
    cout << sum;
    return 0;
}