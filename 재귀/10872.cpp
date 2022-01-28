//팩토리얼
#include<bits/stdc++.h>
using namespace std;

int ret = 1;
int func(int n){
    if(n==0) return ret;
    ret *= n;
    func(n-1);
    return ret;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << func(n);
}