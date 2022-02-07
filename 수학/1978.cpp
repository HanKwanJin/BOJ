//소수찾기
#include<bits/stdc++.h>
using namespace std;

int n;
int cnt;
bool func(int x){
    if(x == 1) return false;
    for(int i=2; i<= sqrt(x); i++){
        for(int j=i+i; j<= x; j += i){
            if(j == x) return false;
        }
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    while(n--){
        int x;
        cin >> x;
        if(func(x)) cnt++;
    }
    cout << cnt;
    return 0;
}