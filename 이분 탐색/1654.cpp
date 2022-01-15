//랜선 자르기
#include<bits/stdc++.h>
using namespace std; 

int k,n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    vector<int> v(k);
    for(int & i: v) cin >> i;

    auto f = [&](int x){
        int s =0;
        for(int i: v) if(i >= x) s += i / x;
        return s >= n;
    };
    int st = 1;
    int en = 1e6;
    while(en /= 2){
        while(f(st + en)) st += en;
    }
    cout << st;
}