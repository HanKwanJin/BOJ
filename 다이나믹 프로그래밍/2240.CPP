//자두 나무
#include<bits/stdc++.h>
using namespace std;

int t, w;
int d[31][1001];
int arr[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    int m =0;
    for(int i=1; i <= t; i++){
        cin >> arr[i];
    }
    
    for(int i=1; i<= t; i++){ //0일때 미리 계산
        if(arr[i] == 1){
            d[0][i] = d[0][i-1] + 1;
        }else{
            d[0][i] = d[0][i-1];
        }
        m = max(m, d[0][i]); 
    }

    //짝수번 -> 1 홀수번 -> 2
    for(int i=1; i<= w; i++){ //이동 횟수
        for(int j=1; j<=t; j++){ //시간
            if(i % 2 == 0 && arr[j] == 1){
                d[i][j] = max(d[i][j-1], d[i-1][j-1]) + 1;

            }else if(i % 2 == 1 && arr[j] == 2){
                d[i][j] = max(d[i][j-1], d[i-1][j-1]) + 1;
            }else{
                d[i][j] = max(d[i][j-1], d[i-1][j-1]);
            }
            m = max(m, d[i][j]);
        }

    }
    cout << m;
}