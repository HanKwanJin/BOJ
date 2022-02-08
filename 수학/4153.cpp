//직각삼각형
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());

        if(v[v.size() - 1] == sqrt(pow(v[0],2) + pow(v[1],2))){
            cout << "right" << '\n';
        }else{
            cout << "wrong" << '\n';
        }
    }
    return 0;
}