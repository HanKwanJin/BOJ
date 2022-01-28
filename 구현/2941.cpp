//크로아티아 알파벳
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0; i<s.size();){
        if(s[i] == 'c'){
            if(s[i+1] == '='){
                i += 2;
                cnt++;
            }else if(s[i+1] == '-'){
                i += 2;
                cnt++;
            }else{
                i++;
                cnt++;
            }
        }else if(s[i] == 'd'){
            if(s[i+1] == 'z' && s[i+2] == '='){
                i += 3;
                cnt++;
            }else if(s[i+1] == '-'){
                i +=2;
                cnt++;
            }else{
                i++;
                cnt++;
            }
        }else if(s[i] =='l'){
            if(s[i+1] == 'j'){
                i += 2;
                cnt++;
            }else{
                i++;
                cnt++;
            }
        }else if(s[i] =='n'){
            if(s[i+1] == 'j'){
                i +=2;
                cnt++;
            }else{
                i++;
                cnt++;
            }
        }else if(s[i] =='s'){
            if(s[i+1] == '='){
                i += 2;
                cnt++;
            }else{
                i++;
                cnt++;
            }
        }else if(s[i] =='z'){
            if(s[i+1] == '='){
                i += 2;
                cnt++;
            }else{
                i++;
                cnt++;
            }
        }else{
            i++;
            cnt++;
        }
    }
    cout << cnt;
}