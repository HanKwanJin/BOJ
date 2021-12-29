//평균은 넘겠지
#include<bits/stdc++.h>
using namespace std;
int c;
int n;
int arr[1001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    cout<<fixed;
    cout.precision(3);
    while(c--){
        cin >> n;
        double sum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        sum = sum / n; //평균이됨
        double cnt =0;
        for(int i=0; i<n; i++){
            if(sum < arr[i]){
                cnt++;
            }
        }
        double result = (cnt / n) * 100;
        
        cout << result <<"%" << '\n';
        
    }
}