#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[100005]; //first = end time, second = start time
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a+n);
    int cnt =0;
    int tmp =0;
    for(int i=0; i<n; i++){
        if(tmp > a[i].second ) continue;
        cnt++;
        tmp = a[i].first;
    }
    cout << cnt;
}