#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int n,p,d;
int ret;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int,int>> v;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> d >> p;
        v.push_back({p,d});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }
    while(pq.size()){
        ret += pq.top(); pq.pop();
    }
    cout << ret << '\n';
    return 0;
}