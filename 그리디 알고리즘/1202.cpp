#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
typedef long long ll;
using namespace std;
ll n,k,ret;
ll c[300002];
vector<pair<ll,ll>> v;
priority_queue<ll, vector<ll>> pq;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=0; i<k; i++){
        cin >> c[i];
    }
    sort(v.begin(), v.end());
    sort(c, c+k);
    int j=0;
    for(int i=0; i < k; i++){
        while(j < n && v[j].first <= c[i]) pq.push(v[j++].second);
        if(pq.size()){
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret << '\n';
    return 0;
}