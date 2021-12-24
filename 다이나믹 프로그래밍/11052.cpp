//카드 구매하기
#include<bits/stdc++.h>
using namespace std;

int n;
int d[1001]; //d[i] 카드를 i개 골랐을 때 최대가격
int pr[1001]; //pr[i] i개 카드를 골랐을 때 가격
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<= n; i++){
        cin >> pr[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<= i; j++){
            d[i] = max(d[i], d[i-j]+pr[j]);
        }
    }
    cout << d[n];

}