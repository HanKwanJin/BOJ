#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    pair<int,int> ans = {1000000, -1000000};
    for(int i=0; i<n; i++){
        int a,b; //a->금액, b->배송비
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        int sum = v[i].first - v[i].second;;
        for(int j=i+1; j<n; j++){
            int ret = v[i].first - v[j].second;
            if(ret > 0) sum += ret;
        }

        if(ans.second <= sum){
            if(ans.second < sum){
                ans = {v[i].first, sum};
            }else if(ans.first > v[i].first){
                ans.first = v[i].first;
            }
        }

    }
    if(ans.second > 0) cout << ans.first;
    else cout << 0;
}