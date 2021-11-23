#include<bits/stdc++.h>
using namespace std;
 
vector<string> v[201];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    

    for(int i=0; i< n; i++){
        int tmp;
        string tmp_s;
        cin >> tmp >> tmp_s;
        v[tmp].push_back(tmp_s);
    }


    for(int i= 1; i<= 200; i++){
        for(int j=0; j< v[i].size(); j++){
            cout << i << ' ' << v[i][j] << '\n';
        }
    }
}
