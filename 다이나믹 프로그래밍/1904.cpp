//01타일
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll d[1000001]; //d[a] = b 길이가 a일때 경우의 수 b
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1; //1
    d[2] = 2; //00, 11
    for(int i=3; i<= n; i++){
        d[i] = (d[i-1] + d[i-2]) % 15746;
    }
    cout << d[n];
}