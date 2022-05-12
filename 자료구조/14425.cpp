#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
int n,m;
int ret;
set<string> s;
vector<string> a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i=0; i<m; i++){
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for(string e : a){
        if(s.find(e) != s.end()) ret++;
    }
    cout << ret;
}