#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
int n,x,y;
int r,l;
int ret;
pair<int,int> a[1000001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n);
    l = a[0].first;
    r = a[0].second;
    for(int i=1; i<n; i++){
        if(a[i].first > r) {
            ret += r - l;
            l = a[i].first;
            r = a[i].second;
        }else if(a[i].second > r && a[i].first > l){
            r = a[i].second;
        }
    }
    ret += r - l;
    cout << ret;
    return 0;
}