//덩치
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
int arr[51];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                cnt++;
            }
        }
        arr[i] = cnt + 1;
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
}