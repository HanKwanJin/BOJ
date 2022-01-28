//다이얼
#include<bits/stdc++.h>
using namespace std;

int func(char c){
    int t = 0;
    if( c=='A' || c=='B' || c=='C') t += 3;
    if( c=='D' || c=='E' || c=='F') t += 4;
    if( c=='G' || c=='H' || c=='I') t += 5;
    if( c=='J' || c=='K' || c=='L') t += 6;
    if( c=='M' || c=='N' || c=='O') t += 7;
    if( c=='P' || c=='Q' || c=='R' || c=='S') t += 8;
    if( c=='T' || c=='U' || c=='V') t += 9;
    if( c=='W' || c=='X' || c=='Y' || c=='Z') t += 10;
    return t;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ret = 0;
    for(int i=0; i<s.size(); i++){
        ret += func(s[i]);
    }
    cout << ret;
}