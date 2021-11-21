#include<bits/stdc++.h>
using namespace std;

int n;
string s[51];
bool cmp(string& a, string& b){
    if(a.size() != b.size()) return a.size() < b.size();
    int a_sum =0 ,b_sum =0;
    for(int i=0; i< a.size(); i++){
        if('0' <= a[i] && a[i] <= '9') a_sum += a[i] - '0';
        if('0' <= b[i] && b[i] <= '9') b_sum += b[i] - '0';
    }
    if(a_sum != b_sum) return a_sum < b_sum;
    
    return a < b;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    sort(s,s+n,cmp);

    for(int i=0; i<n; i++){
        cout << s[i] << '\n';
    }

}