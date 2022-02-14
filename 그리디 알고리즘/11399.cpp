//ATM
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    int sum = 0;
    int cur = 0;
    for(int i=1; i<=n; i++){
        cur += arr[i];
        sum += cur;
    }  
    cout << sum; 
}