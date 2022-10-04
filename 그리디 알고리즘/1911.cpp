#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
typedef long long ll;
using namespace std;
ll n,m,lst,d,ret;
vector<pair<ll,ll>> v;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        ll st,en;
        cin >> st >> en;
        v.push_back({st, en});
    }
    sort(v.begin(), v.end()); //시작 위치를 기준으로 정렬
    for(int i=0; i<v.size(); i++){
        if(v[i].second <= lst) continue;
        if(lst < v[i].first){
            int b = (v[i].second - v[i].first) / m + ((v[i].second - v[i].first) % m ? 1 :0);
            ret += b;
            lst = v[i].first + b * m;
        }else{
            int b = (v[i].second - lst) / m + ((v[i].second - lst) % m ? 1 : 0);
            ret += b;
            lst = lst + b * m;
        }
    }
    cout << ret << '\n';
    return 0;
}