//ACM 호텔
#include<bits/stdc++.h>
using namespace std;
int t, h,w,n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    int y,x;
    while(t--){
        cin >> h >> w >> n;
        if(n <= h){
            y = n;
            x = 1;
        }else{
            y=n-h;
            x=2;
        }
        while(y-h > 0){
            x++;
            y -= h;
        }
        cout << y;
        if(x < 10){
            cout << 0 << x <<'\n';
        }else{
            cout << x << '\n';
        }
    }
}