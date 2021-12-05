#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100001];
int ms;
bool cmp(int& a, int & b){
    return a > b;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,cmp);
    ms = arr[0];
    for(int i=1; i<n; i++){
        ms = max(ms, arr[i] * (i+1));
    }
    cout << ms;
}