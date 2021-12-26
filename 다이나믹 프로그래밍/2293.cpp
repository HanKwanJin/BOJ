//동전1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll d[10001]; //d[a] = b a원을 만들기 위한 경우의 수가 b임
int coin[101];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> coin[i];
    }
    d[0] = 1; //아무것도 선택 안했을때 0을 만드는 경우의 수는 1이다
    for(int i=1; i<= n; i++){
        for(int j=coin[i]; j<= k; j++){
            d[j] = d[j] + d[j-coin[i]]; 
        }
    }
    cout << d[k];
}
