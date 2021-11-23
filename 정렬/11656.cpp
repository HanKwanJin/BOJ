#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string tmp[1001];
    cin >> s;
    int d = s.size();
    for(int i=0; i< d; i++){
        for(int j =i; j< d; j++){
            tmp[i] += s[j];
        }
    }

    sort(tmp, tmp+d);
    for(int i=0; i< d; i++){
        cout << tmp[i] << '\n';
    }
} 
 
