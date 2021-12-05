#include<bits/stdc++.h>
#define w first
#define v second
using namespace std;
int n,k;
int d[101][100001];//d[idx][무게]
pair<int,int> s[101];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i=1; i <= n; i++){
        cin >> s[i].w >> s[i].v;
    }
    for(int i=1; i<= n; i++){
        for(int j=1; j<=k; j++){
            if(j >= s[i].w){
                d[i][j] = max(d[i-1][j], d[i-1][j-s[i].w] + s[i].v);
            }else{
                d[i][j] = d[i-1][j];
            }
        }
    }
    cout << d[n][k];
}