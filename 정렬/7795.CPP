#include<bits/stdc++.h>
using namespace std;

int n,m;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<pair<int,int>> v;
        int cnt=0, ans =0;
        for(int i=0; i< n; i++){
            int x;
            cin >> x;
            v.push_back({x,0});
        }
        for(int i=0; i < m; i++){
            int x;
            cin >> x;
            v.push_back({x,1});
        }

        sort(v.begin(), v.end());
        for(int i=0; i<n+m; i++){
            if(v[i].second == 0){
                ans += cnt;
            }else{
                cnt++;
            }
        }

        cout << ans << '\n';
    }
}