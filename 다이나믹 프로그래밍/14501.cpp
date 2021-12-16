//14501 퇴사
#include<bits/stdc++.h>
using namespace std;

int d[16];
pair<int,int> arr[16]; //time pay
int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n;
    
    int m = 0;
    for(int i = 1; i<= n; i++){
        cin >> arr[i].first >> arr[i].second;
        for(int j=0; j<i; j++){
            if(arr[j].first + j <= i && arr[i].first + i <= n+1){
                d[i] = max(d[i], d[j] + arr[i].second);
            }
        }
        m = max(m, d[i]);
    }
    
    cout << m;

}