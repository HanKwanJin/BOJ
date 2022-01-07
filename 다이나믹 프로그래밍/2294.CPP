//동전 2 
#include<bits/stdc++.h>
using namespace std;

int n,k;
long long d[10001];
int arr[101];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=k; i++){
        d[i] = 999999;
    }
    for(int i=1; i<=n; i++){
        for(int j=arr[i]; j<= k; j++){
            d[j] = min(d[j], d[j-arr[i]] + 1);
        }
    }
    if(d[k] == 999999){
        cout << -1;
    }else{
        cout << d[k];
    }
}
