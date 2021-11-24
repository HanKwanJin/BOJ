#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000001];
int cnt;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        a[num]++;
    }

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(a[num] == 0) cnt++; //교환 안된 사람
        else a[num]--; //교환 된 사람
    }

    cout << cnt;
    
}