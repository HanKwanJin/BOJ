//가장 긴 바이토닉 부분 수열
#include<bits/stdc++.h>
using namespace std;
int dp[1001];
int n;
int arr[1001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int mx = 0; 
    for(int i=1; i<= n; i++){
        for(int j=1; j<i; j++){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        mx = max(mx, dp[i]);
    }
    cout << mx;
}