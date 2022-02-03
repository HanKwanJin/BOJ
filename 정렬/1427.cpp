//소트인사이드
#include<bits/stdc++.h>
using namespace std;

int n;
bool cmp(int & a, int & b){
    return a > b;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v;
    int ns = to_string(n).size();
    for(int i=0; i< ns; i++){
        int x = n % 10;
        n /= 10;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i < v.size(); i++){
        cout << v[i];
    }
}