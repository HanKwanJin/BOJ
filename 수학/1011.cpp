//Fly me to the Alpha Centauri
#include<bits/stdc++.h>
using namespace std;
typedef double d;
int t;
d x,y;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> y;
        d i =1;
        d ret = y-x;
        for(;; i++){ 
            if(ret < i*i){
                break;
            }
        }
        if(ret == (i-1)*(i-1)){
            cout << 2 * (i-1) - 1 << '\n';
        }else if(ret < ((i-1)*(i-1) + i*i) / 2){
            cout << 2 * (i-1) << '\n';
        }else{
            cout << 2 * i - 1 << '\n';
        }
    }
    return 0;
}