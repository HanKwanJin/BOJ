//연산자 끼워넣기
#include<bits/stdc++.h>
using namespace std;
int n;
const int INF = 987654321;
int mn = INF;
int mx = -INF;
vector<int> v;
int Plus,Minus,Multi,Divide;
void input(){    
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> Plus >> Minus >> Multi >> Divide; 
}

void func(int pl, int mi, int mu, int di, int sum, int nx, int cnt){
    if(cnt == n-1){
        mn = min(mn, sum);
        mx = max(mx, sum);
        return;
    }
    if(pl < Plus) func(pl+1, mi, mu, di, sum+v[nx], nx+1, cnt+1);
    if(mi < Minus) func(pl, mi+1, mu, di, sum-v[nx], nx+1, cnt+1);
    if(mu < Multi) func(pl, mi, mu+1, di, sum * v[nx], nx+1, cnt+1);
    if(di < Divide) func(pl, mi, mu, di+1, sum / v[nx], nx+1, cnt+1);
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();   
    func(0, 0,0,0, v[0], 1, 0);
    cout << mx << '\n' << mn;
    return 0;
}