#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<int> s1;
set<int> s2;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s1.insert(x);
    }
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        if(s1.find(x) != s1.end()){
            s1.erase(x);
        }else{
            s2.insert(x);
        }
    }
    cout << s1.size() + s2.size();
    return 0;
}