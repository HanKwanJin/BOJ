#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    vector<int> v;
    while(1){
        if(n == 0) break;
        
        if(n % -2 == 0) //짝수
        {
            v.push_back(0);
            n /= -2;
        }else{ //홀수
            v.push_back(1);
            n = (n-1)/-2;
        }
    }
    reverse(v.begin(),v.end());
    for(auto c: v){
        cout << c;
    }
}