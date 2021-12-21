//1,2,3 더하기 3
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll d[1000001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    d[1] = 1; 
    d[2] = 2;
    d[3] = 4;
    for(int i=4; i<= 1000000; i++){
        d[i] = (d[i-3] + d[i-2] + d[i-1]) % 1000000009;
    }
    for(int i=0; i<t; i++){
        cin >> n;
        cout << d[n] << '\n';
    }
}