//피보나치 수의 확장
#include<bits/stdc++.h>
#define moduler 1000000000
typedef long long ll;
using namespace std;
int n;
int d[1000001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    //n이 음수면 짝수 일때 -1
    int z = abs(n);
    d[0] = 0;
    d[1] = 1;
    for(int i=2; i<= z; i++){
        d[i] = (d[i-1] + d[i-2]) % moduler;
    }
    if(n == 0){
        cout << 0 << '\n';
        cout << d[0];
    }
    else if(n < 0 && z % 2 == 0){ //짝수
        cout << -1 << '\n';
        cout << d[z];
    }else if(n < 0 && z % 2 == 1){
        cout << 1 << '\n';
        cout << d[z];
    }else{
        cout << 1 << '\n';
        cout << d[z];
    }
}