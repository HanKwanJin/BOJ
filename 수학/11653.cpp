//소인수분해
#include<bits/stdc++.h>
using namespace std;

bool prime[10000001];
vector<int> v;
vector<int> ret;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<= sqrt(n); i++){
        if(prime[i]){
            for(int j= i+i; j<= n; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i=2; i<= n; i++){
        if(prime[i]){
            v.push_back(i);
        }
    }
    while(n != 1){
        for(int i=0; i< v.size(); i++){
            if(v[i] <= n){
                if(n % v[i] == 0){
                    ret.push_back(v[i]);
                    n /= v[i];
                    break;
                }
            }
        }
    }
    for(int i=0; i<ret.size(); i++){
        cout << ret[i] << '\n';
    }
}