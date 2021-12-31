//타일 채우기
#include<bits/stdc++.h>
using namespace std;
int n;
int d[31];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    if(n % 2 == 1){
        cout << 0;
        return 0;
    }
    for(int i=4; i<=n; i = i + 2){
        d[i] = d[i-2] * d[2];
        for(int j = i-4; j >= 0; j = j-2){
            d[i] += d[j] * 2;
        }
    }
    cout << d[n];
}