#include<bits/stdc++.h>
using namespace std;



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        int x;
        int y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end());

    for(int i=0; i< v.size(); i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    
}