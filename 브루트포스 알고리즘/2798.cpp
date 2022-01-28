//블랙잭
#include<bits/stdc++.h>
using namespace std;
int card[101];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> card[i];
    }
    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int sum = card[i] + card[j] + card[k];
                if(sum <= m){
                    mx = max(mx, sum);
                }
            }
        }
    }
    cout << mx;
}