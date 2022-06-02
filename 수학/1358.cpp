#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w,h,x,y,p;
    int ret = 0;
    cin >> w >> h >> x >> y >> p;
    int r = h/2;
    while(p--){
        int cx, cy;
        cin >> cx >> cy;
        if(x <= cx && y <= cy && x + w >= cx && y + h >= cy) ret++;
        else if((x-cx)*(x-cx) + (y+r-cy)*(y+r-cy) <= r*r) ret++;
        else if((x+w-cx)*(x+w-cx) + (y+r-cy)*(y+r-cy) <= r*r) ret++;
    }
    cout << ret;
}