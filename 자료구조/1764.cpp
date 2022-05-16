#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int n,m;
string a;
vector<string> v;
set<string> s;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a;
        s.insert(a);
    }
    for(int i=0; i<m; i++){
        cin >> a;
        if(s.find(a) != s.end()){
            v.push_back(a);
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for(string e: v){
        cout << e << '\n';
    }
    return 0;
}