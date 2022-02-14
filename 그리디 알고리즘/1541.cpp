//잃어버린 괄호
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    bool isMinus = false;
    int ret =0;
    string tmp ="";
    for(int i=0; i<= s.size(); i++){
        if(s[i] == '-' || s[i] == '+' || i == s.size()){
            if(isMinus){
                ret -= stoi(tmp);
                tmp = "";
            }else{
                ret += stoi(tmp);
                tmp ="";
            }
        }else{
            tmp += s[i];
        }
        if(s[i] == '-') isMinus = true;
    }   

    cout << ret;
    return 0;
}