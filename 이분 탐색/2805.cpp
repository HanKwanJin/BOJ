//나무 자르기
#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int st = 0;
    int en = *max_element(v.begin(), v.end());
    
    int ret =0;
    while(st <= en){
        int mid = (st + en) / 2;
        long long int cnt =0;
        for(int i=0; i< n; i++){
            if(v[i] >= mid){
                cnt += v[i] - mid;
            }
            
        }
        if(cnt < m){
            en = mid - 1;
        }else{
            ret = mid;
            st = mid + 1;
        }
    }
    cout << ret;
}