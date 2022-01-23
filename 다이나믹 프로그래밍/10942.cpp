//팰린드롬?
#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[2001];
bool chk[2001][2001]; // chk[a][b] a부터 b까지 가능한지
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(chk, false, sizeof(chk));
    cin >> n;
    for(int i=1; i<=n; i++) cin >> p[i];
    //길이 1
    for(int i=1; i<=n; i++) chk[i][i] = true;
    //길이 2
    for(int i=1; i<n; i++) {
        if(p[i] == p[i+1]) chk[i][i+1] = true;
    }
    //길이 3 이상
    for(int i=2; i< n; i++){
        for(int j=1; j<= n-i; j++){
            if(p[j] == p[j+i] && chk[j+1][j+i-1]){
                //앞과 뒤가 같고 그 사이가 팰린드롬인 경우
                chk[j][j+i] = true;
            } 
        }
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        cout << chk[a][b] << '\n';
    }
    

    return 0;
}