//암호 코드
#include <iostream>
#define m 1000000
using namespace std;
string s;
int d[5001];
int arr[5001];
int main()
{
    cin >> s;
    int len = s.size();
    for(int i=1; i<=len; i++){
        arr[i] = s[i-1] - '0';
    }
    if(len == 1 && arr[1] == 0){
        cout << 0;
        return 0;
    }
    d[0] = 1;
    for(int i=1; i<= len; i++){
        if(arr[i] >= 1 && arr[i] <= 9){
            d[i] = (d[i-1] + d[i]) % m;
        }
        int tmp = arr[i] + arr[i-1]*10;
        if(tmp >= 10 && tmp <= 26){
            d[i] = (d[i-2] + d[i]) % m;
        }
    }
    cout << d[len];

}

