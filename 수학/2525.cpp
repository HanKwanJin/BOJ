//오븐 시계
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin >> a >> b;
    cin >> c;
    a += (b+c) / 60;
    b = (b+c) % 60;
    cout << a % 24 << " " << b % 60;
}