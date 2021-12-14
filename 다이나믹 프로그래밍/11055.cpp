#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int d[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m =0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++){
        d[i] = arr[i];
        for(int j=0; j < i; j++){
            if(arr[i] > arr[j]){
                d[i] = max(d[i], d[j] + arr[i]);
            }
        }
        m = max(m, d[i]);
    }

    cout << m;

}