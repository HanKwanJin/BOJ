//네 번째 점
#include<bits/stdc++.h>
using namespace std;
int xarr[1001];
int yarr[1001];
vector<pair<int,int>> v;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    for(int i=0; i<3; i++){
        cin >> x >> y;
        xarr[x]++;
        yarr[y]++;
        v.push_back({x,y});
    }
    int retx,rety;
    for(int i=0; i< v.size(); i++){
        if(xarr[v[i].first] == 1){
            retx = v[i].first;
        }
        if(yarr[v[i].second] == 1){
            rety = v[i].second;
        }
    }

    cout << retx << ' ' << rety << '\n';
    return 0;
}