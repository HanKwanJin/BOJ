//극장 좌석
#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[41];
int d[41];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> m;

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;

    for(int i=4; i<= n; i++){
        d[i] = d[i-1] + d[i-2];
    }
    
    for(int i=1; i<=m; i++){
        cin >> arr[i];
    }
    int ret = 1;
    for(int i=1; i<=m; i++){
        ret *= d[arr[i] - arr[i-1] - 1];
    }
    ret *= d[n-arr[m]];
    cout << ret;

}