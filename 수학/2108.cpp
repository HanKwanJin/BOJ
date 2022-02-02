//통계학
#include <bits/stdc++.h>
using namespace std;
int n;
double sum;
int num[8001];
int mx;
bool chk;
vector<int> a;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i=0; i<n; i++){
        int x;
        int idx =0;
        cin >> x;
        a.push_back(x);
        sum += x;
        if(x <= 0){
            idx = -x;
        }else{
            idx = 4000 + x;
        }
        num[idx]++;
        if(num[idx] > mx){
            mx = num[idx];
        }
    }
    cout << round(sum / double(n)) <<'\n';
    sort(a.begin(), a.end());
    cout << a[a.size()/2] << '\n';
    int ret =0;
    for(int i=-4000; i<=4000; i++){
        int idx=0;
        if(i <= 0){
            idx = -i;
        }else{
            idx = 4000 + i;
        }
        if(num[idx] == mx){
            ret = i;
            if(chk) break;
            chk = true;
        }
    }
    cout <<ret << '\n';
    cout << a[a.size() - 1] - a[0] << '\n';
}