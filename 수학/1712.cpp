//손익분기점
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c;
    cin >> a >> b >> c;
    long long cnt = 0;
    if(b >= c){
        cout << -1;
        return 0;
    }
    cout << a / (c - b) + 1;
}