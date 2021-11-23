#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
int n;
     

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<string> v(n);
    vector<ll> a;
    for(int i=0; i<n; i++){
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());
        a.push_back(stoll(v[i]));
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n; i++){
        cout << a[i] << '\n';
    }


}
