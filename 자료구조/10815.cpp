#include<iostream>
#include<algorithm>
using namespace std;

int a[500001];
int n,m;
bool func(int c, int l){
    int st = 0;
    int en = l;
    while(st < en){
        int mid = (st + en) / 2;
        if(a[mid] > c) en = mid;
        else if(a[mid] == c) return true;
        else st = mid + 1;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cin >> m;
    for(int i=0; i<m; i++){
        int c;
        cin >> c;
        cout << func(c,n) << " ";
    }
    return 0;
}