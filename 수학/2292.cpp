//벌집
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1){
        cout << 1;
        return 0;
    }
    int i=0;
    for(int sum = 2; sum <= n; i++){
        sum += i*6;
    }
    cout << i;
}