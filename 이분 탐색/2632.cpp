#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int t,n,m,ret;
int a[1004], b[1004], asum[2004], bsum[2004];
map<int,int> acnt, bcnt;

void make(int n, int psum[], map<int,int>& _map){
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n+i-1; j++){
            int sum = psum[j] - psum[j-i];
            _map[sum]++;
            if(i == n) break; 
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        asum[i] = asum[i-1] + a[i];
    }
    for(int i=n+1; i<=2*n; i++){
        asum[i] = asum[i-1] + a[i-n];
    }

    for(int i=1; i<=m; i++) cin >> b[i];
    for(int i=1; i<=m; i++){
        bsum[i] = bsum[i-1] + b[i];
    }
    for(int i=m+1; i<=2*m; i++){
        bsum[i] = bsum[i-1] + b[i-m];
    }

    make(n, asum, acnt);
    make(m, bsum, bcnt);
    int ret = 0;
    for(int i=1; i<t; i++){
        ret += acnt[t-i] * bcnt[i];
    }
    ret += acnt[t];
    ret += bcnt[t];
    cout << ret;
    return 0;
}