//그룹 단어 체커
#include<bits/stdc++.h>
using namespace std;
bool group(string s){
    char cur = s[0];
    map<char, bool> m;
    m.insert({s[0], true});
    for(int i=1; i< s.size(); i++){
        if(s[i] != cur){
            if(m[s[i]]){ //중복된 값이면 false 를 반환
                return false;
            }else{ 
                cur = s[i];
                m[s[i]] = true;
            }
        }
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int cnt = 0;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(group(s)){
            cnt++;
        }
    }
    cout << cnt;

}