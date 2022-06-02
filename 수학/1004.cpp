#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x1,y1,x2,y2;
        int n;
        int ret = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        while(n--){
            bool st = false, en = false;
            int x,y,r;
            cin >> x >> y >> r;
            if((x1-x)*(x1-x) + (y1-y)*(y1-y) < r*r) st = true;
            if((x2-x)*(x2-x) + (y2-y)*(y2-y) < r*r) en = true;
            if(st != en) ret++;
        }
        cout << ret << '\n';
    }
}