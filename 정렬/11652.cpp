#include<bits/stdc++.h>
using namespace std;

int n;
int cnt, maxCnt;
long long maxValue = -(1ll << 62) -1; 
long long arr[100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i= 0; i < n; i++){
        cin >> arr[i];
    } 
    sort(arr,arr+n);

    cnt =0;
    for(int i=0; i<n; i++){
        if(i ==0 || arr[i-1] == arr[i]) cnt++;
        else{
            if(cnt > maxCnt){
                maxCnt = cnt;
                maxValue = arr[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > maxCnt) maxValue = arr[n-1];
    cout << maxValue;
}
