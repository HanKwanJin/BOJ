//체스판 다시 칠하기
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int INF = 987654321;
vector<string> v;
string wb[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string bw[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};
int wcnt(int y, int x){
    int cnt =0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(v[y+i][x+j] != wb[i][j]) cnt++;
        }
    }
    return cnt;
}
int bcnt(int y, int x){
    int cnt =0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(v[y+i][x+j] != bw[i][j]) cnt++;
        }
    }

    return cnt;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    int mn = INF;
    for(int i=0; i+8<=n; i++){
        for(int j=0; j+8<=m; j++){
           mn = min({mn, wcnt(i,j), bcnt(i,j)});
        }
    }
    cout << mn;
    return 0;
}