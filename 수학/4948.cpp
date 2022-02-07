//베르트랑 공준
#include<bits/stdc++.h>
using namespace std;

bool prime[300000];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    while(1){
        int cnt =0;
        cin >> n;
        if(n == 0) break;
        memset(prime, true, sizeof(prime));
        prime[0] = false;
        prime[1] = false;
        for(int i=2; i<= sqrt(2*n); i++){
            if(prime[i]){
                for(int j= i+i; j<= 2*n; j+= i){
                    prime[j] = false;
                }
            }
        }

        for(int i=n+1; i <= 2*n; i++){
            if(prime[i]){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}