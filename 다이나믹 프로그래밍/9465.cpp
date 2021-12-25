//스티커
#include<bits/stdc++.h>
using namespace std;
int t,n;
int d[3][100001];
int arr[3][100001]; 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i <= 2; i++){
            for(int j=1; j<= n; j++){
                cin >> arr[i][j];
            }
        }
        //d[1][1], d[2][1] 둘중에 하나는 꼭 골라야 한다.
        d[1][1] = arr[1][1];
        d[2][1] = arr[2][1];
        d[1][2] = arr[1][2] + d[2][1];
        d[2][2] = arr[2][2] + d[1][1];

        for(int i=3; i<= n; i++){
            //한칸 떨어진 대각선에 있는 스티커를 고르는 것과
            //바로 옆에 있는 대각선에 스티커를 고르는 것 중에 큰 값
            d[1][i] = max(d[2][i-1], d[2][i-2]) + arr[1][i];
            d[2][i] = max(d[1][i-1], d[1][i-2]) + arr[2][i];
        }
        cout << max(d[1][n], d[2][n]) << '\n';
    }
}