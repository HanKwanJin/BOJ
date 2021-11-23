#include<bits/stdc++.h>
using namespace std;
//kadane's algorithm 참고
int n;
int d[100001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> d[i];
    }
    for(int i=1; i<=n; i++){
        d[i] = max(d[i], d[i] + d[i-1]);
    }

    cout << *max_element(d+1,d+n+1) << '\n';
}
