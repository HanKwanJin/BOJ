//골드바흐의 추측
#include<bits/stdc++.h>
using namespace std;

bool p[10001];
const int INF = 987654321;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        vector<tuple<int,int,int>> a;
        memset(p, true, sizeof(p));
        p[0] = false;
        p[1] = false;
        for(int i=2; i<= sqrt(n); i++){
            if(p[i]){
                for(int j=i+i; j<=n; j+=i){
                    p[j] = false;
                }
            }
        }
        for(int i=1; i<= n; i++){
            if(p[i]) v.push_back(i);
        }
        int mn = INF;
        for(int i=0; i< v.size(); i++){
            for(int j=i; j<v.size(); j++){
                if(v[i] + v[j] == n){
                    a.push_back({v[i],v[j], abs(v[i]-v[j])});
                    mn = min(mn, abs(v[i]-v[j]));
                }
            }
        }
        
        for(int i=0; i< a.size(); i++){
            int x,y,z;
            tie(x,y,z) = a[i];
            if(z == mn){
                cout << x << ' ' << y << '\n';
            }
        }
    }   
}