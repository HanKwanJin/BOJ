//피보나치 수 5
#include<bits/stdc++.h>
using namespace std;

int ret = 0;
int func(int n){
    if(n == 0) return 0;
    if(n == 1){return 1;}
    ret = func(n-1) + func(n-2);
    return ret;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << func(n);
}