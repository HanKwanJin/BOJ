//소수
#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
bool a[10001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int mn, mx;
    int mp = INF;
    int sum = 0;
    cin >> mn >> mx;
    memset(a, true, sizeof(a));
    a[0] = false;
    a[1] = false;
    for(int i= 2; i<= sqrt(mx); i++){
        if(a[i]){
            for(int j= i+i; j<= mx; j += i){
                a[j] = false;
            }
       }
    }

    for(int i=mn; i<= mx; i++){
        if(a[i]){
            if(mp == INF) mp = i;
            sum += i;
        }
    }
    if(sum == 0) cout << -1;
    else{
        cout << sum << '\n';
        cout << mp;
    }
    return 0;
}