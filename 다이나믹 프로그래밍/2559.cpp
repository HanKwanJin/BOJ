#include<iostream>
#include<algorithm>
using namespace std;
int arr[100002];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    
    int sum = 0;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        if(i < k){
            sum += arr[i];
        }
    }
    int mx = sum;
    for(int i=0; i<n-k; i++){
        sum += arr[i+k];
        sum -= arr[i];
        mx = max(mx, sum);
    }
    cout << mx;
}