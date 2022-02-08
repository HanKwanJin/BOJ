//직사각형에서 탈출
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y,w,h;
    int mn = 0;
    cin >> x >> y >> w >> h;
    mn = min({x, y, w-x, h-y});
    cout << mn;
}