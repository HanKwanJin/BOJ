//삼각 그래프
#include<bits/stdc++.h>
using namespace std;
int n; //y축
long long d[100001][4];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 1;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=3 ; j++){
                cin >> d[i][j];
            }
        }
        d[1][1] = 9999;
        d[1][3] += d[1][2]; //첫줄은 가운데를 거쳐야함
        for(int i=2; i<= n; i++){
            d[i][1] += min(d[i-1][1], d[i-1][2]);
            d[i][2] += min({d[i-1][1], d[i-1][2], d[i-1][3], d[i][1]});
            d[i][3] += min({d[i-1][2], d[i-1][3], d[i][2]});
    
        }
        cout << cnt << ". " << d[n][2] << '\n';
        cnt++; //k. n 다음 케이스 번호
    }
}