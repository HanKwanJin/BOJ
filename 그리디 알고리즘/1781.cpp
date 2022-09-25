#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
typedef long long ll;
using namespace std;
ll n,ret;
vector<pair<ll, ll>> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        ll a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end()); //데드라인 기준으로 정렬
    
    for(int i=0; i<v.size(); i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }
    while(!pq.empty()){
        ret += pq.top();
        pq.pop();
    }
    cout << ret << '\n';
    return 0;
}