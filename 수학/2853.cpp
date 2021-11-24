#include<bits/stdc++.h>
using namespace std;

int n;
int arr[5002];
int cnt;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=1; i<n; i++){
        int s = arr[i];
        if(s > 0){
            cnt++;
            for(int j=i+1; j<n; j++){
                if(((arr[j] -1 ) % (s-1)) == 0){
                    arr[j] = 0;
                }
            }
        }
        
    }

    cout << cnt;
    
}