//가장 긴 증가하는 부분 수열 4
#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int d[1001];
vector<int> v[1001];
vector<int> ans;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++){
        d[i] = 1;
        v[i].push_back(arr[i]);
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                if(d[i] < d[j] + 1){ //길이 갱신
                    v[i].clear();
                    v[i] = v[j];
                    v[i].push_back(arr[i]);
                    d[i] = d[j] + 1;
                }   
            }
        }
        if(ans.size() < v[i].size()){
            ans = v[i];
        }
    }
    cout << ans.size() << '\n';
    for(int i =0; i< ans.size(); i++){
        cout << ans[i] << ' ';
    }
}