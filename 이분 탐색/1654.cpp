#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n,k; //k 랜선개수, n 필요한 랜선 개수
ll arr[10001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for(ll i=0; i<k; i++){
        cin >> arr[i];
    }
    sort(arr,arr+k);
    ll left = 1;
    ll right = arr[k-1];
    ll mid =0;
    ll cnt=0;


    if(n == 1){
        cout << arr[0];
        return 0;
    }

    while(left <= right || cnt < n){
        mid = (left + right) / 2;
        cnt =0;

        for(ll i=0; i<k; i++){
            cnt += arr[i] / mid;
        }

        if(cnt >= n){
            left = mid + 1;
        }else if(cnt < n){
            right = mid - 1;
        }

        
        
    }
    cout << mid << '\n';
}