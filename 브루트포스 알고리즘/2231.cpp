//분해합
#include<bits/stdc++.h>
using namespace std;

int n;
int func(int n){
    for(int i=1; i<= n; i++){
        int isz = to_string(i).size();
        int ret = i;
        int ci = i;
        for(int a=0; a< isz; a++){
            ret += ci % 10;
            ci /= 10;
        }
        if(n == ret){
            return i;
        }
    }
    return 0;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << func(n);
}