#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<int> copy(v);
    sort(copy.begin(), copy.end());
    copy.erase(unique(copy.begin(), copy.end()), copy.end());

    for(int i=0; i<n; i++){
        auto ans = lower_bound(copy.begin(), copy.end(), v[i]) - copy.begin();
        cout << ans <<' ';
    }
}