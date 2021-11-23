#include<bits/stdc++.h>
using namespace std; 

int n;
string s[20001];

bool cmp(string &a, string &b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i< n; i++){
        cin >> s[i];
    }

    sort(s, s+n, cmp);

    for(int i=0; i<n; i++){
        if(i ==0 || s[i-1] != s[i]) cout << s[i] << '\n';
         
    }
}
