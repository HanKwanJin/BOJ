#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
int n,ret;
vector<pair<int,int>> v;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    ret += v[0].first + v[0].second;
    for(int i=1; i<v.size(); i++){
        if(ret <= v[i].first){
            ret = v[i].first + v[i].second;
        }else{
            ret += v[i].second;
        }
    }
    cout << ret << '\n';
    return 0;
}