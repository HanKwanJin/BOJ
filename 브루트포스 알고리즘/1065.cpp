//한 수
#include<bits/stdc++.h>
using namespace std;

bool arr[1001];
bool func(int num){
    int ns = to_string(num).size();
    if(ns == 1 || ns == 2) return true;
    int a[1001] = {0,};
    for(int i=0; i<ns; i++){
        a[i] = num % 10;
        num /= 10;
    }
    int chk = a[0] - a[1];
    for(int i=1; i< ns-1; i++){
        int tmp = a[i] - a[i+1];
        if(chk != tmp) return false;
    }
    return true;
}
int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cnt =0;
    for(int i=1; i<=n; i++){
        arr[i] = func(i);
        if(arr[i]) cnt++;
    }
    cout << cnt;
}