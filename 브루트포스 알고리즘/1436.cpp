//영화감독 숌
#include<bits/stdc++.h>
using namespace std;

bool chk(string s){
    int cnt = 0;
    for(int i=0; i<s.size()-2; i++){
        if(s[i]=='6' && s[i+1] == '6' && s[i+2] == '6') return true;
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 1;
    int ret = 666;
    while(1){
        if(cnt == n){
            cout << ret;
            return 0;
        }
        ret++;
        if(chk(to_string(ret))){
            cnt++;
        }
    }
}